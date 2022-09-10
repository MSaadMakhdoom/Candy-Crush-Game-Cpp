
#include "util.h"



float Deg2Rad(float degree) {
	return (degree / 180.0) * 3.141;
}
float Rad2Deg(float angle) {
	return angle * (180.0 / 3.141);
}
void DrawSquare(int sx, int sy, int size, float color[])
{
	int mx = size, my = size;
	glColor3fv(color);
	glBegin(GL_TRIANGLES);
	glVertex4f(sx, sy, 0, 1);
	glVertex4f(sx + mx - 1, sy, 0, 1);
	glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
	glVertex4f(sx, sy, 0, 1);
	glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
	glVertex4f(sx, sy + my - 1, 0, 1);
	glEnd();
}


void InitRandomizer()
{
	srand((unsigned int)time(0));
}


long GetRandInRange(const long& rmin, const long& rmax)
{
	long range = rmax - rmin;
	long value = (rand() % (long)range) + rmin;
	return value;
}


void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
	float color[])
{
	glColor3fv(color);

	glBegin(GL_TRIANGLES);
	glVertex4i(x1, y1, 0, 1);
	glVertex4i(x2, y2, 0, 1);
	glVertex4i(x3, y3, 0, 1);
	glEnd();
}

const int nvertices = 722;
GLfloat vertices[nvertices][2];
void InitCircleVertices(float radius)
{

	float hdegree = 3.141 / 360.0;
	float angle = 0;
	for (int i = 0; i < nvertices; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}
}


void DrawCircle(float sx, float sy, float radius, float* color)
{
	glColor3fv(color);
	InitCircleVertices(radius);
	glBegin(GL_TRIANGLE_FAN);
	glVertex4f(sx, sy, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(sx + vertices[i][0], sy + vertices[i][1], 0, 1);
	glEnd();
}

void Torus2d(int x /*Starting position x*/, int y /*Starting position Y*/,
	float angle, // starting angle in degrees
	float length,           // length of arc in degrees, >0
	float radius,           // inner radius, >0
	float width,            // width of torus, >0
	unsigned int samples,   // number of circle samples, >=3
	float* color)
{
	angle = Deg2Rad(angle);
	length = Deg2Rad(length);
	if (color)
	{ // set color for the Torus
		glColor3fv(color);
	}
	if (samples < 3)
		samples = 3;
	const float outer = radius + width;
	glBegin(GL_QUAD_STRIP);
	for (unsigned int i = 0; i <= samples; ++i)
	{
		float a = angle + (i / (float)samples) * length;
		glVertex2f(x + radius * cos(a), y + radius * sin(a));
		glVertex2f(x + outer * cos(a), y + outer * sin(a));
	}
	glEnd();
}

void DrawLine(int x1, int y1, int x2, int y2, int lwidth, float* color)
{
	glLineWidth(lwidth);
	if (color)
		glColor3fv(color);
	glBegin(GL_LINES);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0);
	glEnd();
}

void DrawString(int x, int y, int width, int height, const string& score,
	float* color)
{
	float fx = (float)x / width * 2 - 1, fy = (float)y / height * 2 - 1;
	DrawString(fx, fy, score, color);
}

void DrawString(float x, float y, const string& score, float* color)
{

	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLvoid* font_style = GLUT_BITMAP_TIMES_ROMAN_24;
	if (color)
		glColor3fv(color);
	glRasterPos3f(x, y, 1);
	//  Draw the characters one by one
	for (int i = 0; i < score.size(); i++)
		glutBitmapCharacter(font_style, score[i]);
	glPopMatrix();
}

#define ROUNDING_POINT_COUNT 16      

typedef struct
{
	float x;
	float y;

} Vector2f;

void DrawRoundRect(float x, float y, float width, float height, float* color,
	float radius) {
	y = y + height;
	Vector2f top_left[ROUNDING_POINT_COUNT];
	Vector2f bottom_left[ROUNDING_POINT_COUNT];
	Vector2f top_right[ROUNDING_POINT_COUNT];
	Vector2f bottom_right[ROUNDING_POINT_COUNT];

	if (radius == 0.0) {
		radius = MIN(width, height);
		radius *= 0.10;
	}

	int i = 0;
	float x_offset, y_offset;
	float step = (2.0f * 3.141) / (ROUNDING_POINT_COUNT * 4), angle = 0.0f;

	unsigned int index = 0, segment_count = ROUNDING_POINT_COUNT;
	Vector2f bottom_left_corner = { x + radius, y - height + radius };

	while (i != segment_count)
	{
		x_offset = cosf(angle);
		y_offset = sinf(angle);

		top_left[index].x = bottom_left_corner.x - (x_offset * radius);
		top_left[index].y = (height - (radius * 2.0f)) + bottom_left_corner.y
			- (y_offset * radius);

		top_right[index].x = (width - (radius * 2.0f)) + bottom_left_corner.x
			+ (x_offset * radius);
		top_right[index].y = (height - (radius * 2.0f)) + bottom_left_corner.y
			- (y_offset * radius);

		bottom_right[index].x = (width - (radius * 2.0f)) + bottom_left_corner.x
			+ (x_offset * radius);
		bottom_right[index].y = bottom_left_corner.y + (y_offset * radius);

		bottom_left[index].x = bottom_left_corner.x - (x_offset * radius);
		bottom_left[index].y = bottom_left_corner.y + (y_offset * radius);

		angle -= step;

		++index;

		++i;
	}

	static GLubyte clr[] = { 156, 207, 255, 128 };

	if (color)
		glColor4fv(color);
	else
		glColor4ubv(clr);

	glBegin(GL_TRIANGLE_STRIP);
	{
		for (i = segment_count - 1; i >= 0; i--) {
			glVertex2f(top_left[i].x, top_left[i].y);
			glVertex2f(top_right[i].x, top_right[i].y);
		}

		glVertex2f(top_right[0].x, top_right[0].y);
		glVertex2f(top_right[0].x, top_right[0].y);

		glVertex2f(top_right[0].x, top_right[0].y);
		glVertex2f(top_left[0].x, top_left[0].y);
		glVertex2f(bottom_right[0].x, bottom_right[0].y);
		glVertex2f(bottom_left[0].x, bottom_left[0].y);

		for (i = 0; i != segment_count; i++) {
			glVertex2f(bottom_right[i].x, bottom_right[i].y);
			glVertex2f(bottom_left[i].x, bottom_left[i].y);
		}
	}
	glEnd();
}


void RoundRect(int x, int y, int width, int height, int radius,
	int resolution)
{
	float step = (2.0f * 3.141) / resolution, angle = 0.0f, x_offset, y_offset;

	int i = 0;

	unsigned int index = 0, segment_count = (int)(resolution / 4);

	Vector2f* top_left = (Vector2f*)malloc(segment_count * sizeof(Vector2f)),
		* bottom_left = (Vector2f*)malloc(
			segment_count * sizeof(Vector2f)), * top_right =
		(Vector2f*)malloc(segment_count * sizeof(Vector2f)),
		* bottom_right = (Vector2f*)malloc(
			segment_count * sizeof(Vector2f)), bottom_left_corner = { x
			+ radius, y - height + radius };

	while (i != segment_count) {
		x_offset = cosf(angle);
		y_offset = sinf(angle);

		top_left[index].x = bottom_left_corner.x - (x_offset * radius);
		top_left[index].y = (height - (radius * 2.0f)) + bottom_left_corner.y
			- (y_offset * radius);

		top_right[index].x = (width - (radius * 2.0f)) + bottom_left_corner.x
			+ (x_offset * radius);
		top_right[index].y = (height - (radius * 2.0f)) + bottom_left_corner.y
			- (y_offset * radius);

		bottom_right[index].x = (width - (radius * 2.0f)) + bottom_left_corner.x
			+ (x_offset * radius);
		bottom_right[index].y = bottom_left_corner.y + (y_offset * radius);

		bottom_left[index].x = bottom_left_corner.x - (x_offset * radius);
		bottom_left[index].y = bottom_left_corner.y + (y_offset * radius);

		top_left[index].x = roundf(top_left[index].x);
		top_left[index].y = roundf(top_left[index].y);

		top_right[index].x = roundf(top_right[index].x);
		top_right[index].y = roundf(top_right[index].y);

		bottom_right[index].x = roundf(bottom_right[index].x);
		bottom_right[index].y = roundf(bottom_right[index].y);

		bottom_left[index].x = roundf(bottom_left[index].x);
		bottom_left[index].y = roundf(bottom_left[index].y);

		angle -= step;

		++index;

		++i;
	}

	glBegin(GL_TRIANGLE_STRIP);
	{
		{
			i = 0;
			while (i != segment_count)
			{
				glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
				glVertex2i(top_left[i].x, top_left[i].y);

				glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
				glVertex2i(top_right[i].x, top_right[i].y);

				++i;
			}
		}

		glColor4f(0.0f, 1.0f, 0.0f, 1.5f);
		glVertex2i(top_right[0].x, top_right[0].y);

		glColor4f(0.0f, 1.0f, 0.0f, 1.5f);
		glVertex2i(top_right[0].x, top_right[0].y);

		{
			glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
			glVertex2i(top_right[0].x, top_right[0].y);

			glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
			glVertex2i(top_left[0].x, top_left[0].y);

			glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
			glVertex2i(bottom_right[0].x, bottom_right[0].y);

			glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
			glVertex2i(bottom_left[0].x, bottom_left[0].y);
		}

		i = 0;
		while (i != segment_count)
		{
			glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
			glVertex2i(bottom_right[i].x, bottom_right[i].y);

			glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
			glVertex2i(bottom_left[i].x, bottom_left[i].y);

			++i;
		}
	}
	glEnd();

	glBegin(GL_LINE_STRIP);

	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);

	{
		i = (segment_count - 1);
		while (i > -1) {
			glVertex2i(top_left[i].x, top_left[i].y);

			--i;
		}

		i = 0;
		while (i != segment_count) {
			glVertex2i(bottom_left[i].x, bottom_left[i].y);

			++i;
		}

		i = (segment_count - 1);
		while (i > -1) {
			glVertex2i(bottom_right[i].x, bottom_right[i].y);

			--i;
		}

		i = 0;
		while (i != segment_count) {
			glVertex2i(top_right[i].x, top_right[i].y);

			++i;
		}

		glVertex2i(top_left[(segment_count - 1)].x,
			top_left[(segment_count - 1)].y);
	}
	glEnd();

	glBegin(GL_LINES);

	glColor4f(0.0f, 0.5f, 1.0f, 1.0f);

	{
		glVertex2i(top_right[0].x, top_right[0].y);

		glVertex2i(top_left[0].x, top_left[0].y);

		glVertex2i(bottom_left[0].x, bottom_left[0].y);

		glVertex2i(bottom_right[0].x, bottom_right[0].y);
	}
	glEnd();

	free(top_left);
	free(bottom_left);
	free(top_right);
	free(bottom_right);
}

void DrawRectangle(int sx, int sy, int mx, int my, float* color)
{
	glColor3fv(color);
	glBegin(GL_TRIANGLES);
	glVertex4f(sx, sy, 0, 1);
	glVertex4f(sx + mx - 1, sy, 0, 1);
	glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
	glVertex4f(sx, sy, 0, 1);
	glVertex4f(sx + mx - 1, sy + my - 1, 0, 1);
	glVertex4f(sx, sy + my - 1, 0, 1);
	glEnd();
}
string Num2Str(int t)
{
	stringstream s;
	s << t;
	return s.str();
}


string Num3Str(string t)
{
	static string name = t;
	
	
	
	stringstream s;
	s << name;

	cout << "\n\n\n\nPlayer name" << name << endl;
	return s.str();
}


void ReadImage(string imgname, vector<unsigned char>& imgArray) {
	using namespace cimg_library;
	CImg<unsigned char> img(imgname.c_str());
	imgArray.resize(img.height() * img.width() * 3, 0);
	int k = 0;
	unsigned char* rp = img.data();
	unsigned char* gp = img.data() + img.height() * img.width();
	unsigned char* bp = gp + img.height() * img.width();

	for (int j = 0; j < img.width(); ++j) {
		int t = j;
		for (int i = 0; i < img.height(); ++i, t += img.width()) {
			imgArray[k++] = rp[t];
			imgArray[k++] = gp[t];
			imgArray[k++] = bp[t];
		}
	}
}
