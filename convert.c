#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

char function_name[256];
int function = 0;

static void handle_ident(FILE *f)
{
	char buf[256];
	int len = 0;

	int uppercase = 0;
	int lowercase = 0;
	for (;;) {
		int c = fgetc(f);
		if (c == EOF)
			break;

		switch (c) {
		case 'A' ... 'Z':
			uppercase = 1;
			buf[len++] = c;
			continue;
		case 'a' ... 'z':
			lowercase = 1;
			buf[len++] = c;
			continue;
		case '0' ... '9':
		case '_':
			buf[len++] = c;
			continue;
		}

		ungetc(c, f);
		break;
	}
	buf[len] = 0;

	if (!uppercase || !lowercase) {
		printf("%s", buf);
		return;
	}

	if (strcmp(buf, "VkExtent2D") == 0) {
		printf("vk_extent_2d");
		return;
	}

	if (strcmp(buf, "VkExtent3D") == 0) {
		printf("vk_extent_3d");
		return;
	}

	const char *win32_ptr = strstr(buf, "Win32");
	int win32_end = win32_ptr ? win32_ptr - buf + 5 : -1;

	if (buf[0] == 'v' && buf[1] == 'k') {
		memcpy(function_name, buf, sizeof(buf));
		function = 1;
	}

	char prev = 'A';
	for (int i = 0; i < len; i++) {
		char c = buf[i];
		if (isupper(c) && islower(prev))
			fputc('_', stdout);
		if (i == win32_end)
			fputc('_', stdout);
		fputc(tolower(c), stdout);
		prev = c;
	}
}

static void handle_string(FILE *f)
{
	int escaped = 0;
	for (;;) {
		int c = fgetc(f);
		if (c == EOF)
			break;

		fputc(c, stdout);

		if (escaped) {
			escaped = 0;
			continue;
		}

		if (c == '"')
			break;
		if (c == '\\')
			escaped = 1;
	}
}

int main(int argc, const char *const *argv)
{
	if (argc < 3) {
		printf("usage: convert IN OUT\n");
		return 0;
	}

	freopen(argv[2], "wb", stdout);

	FILE *f = fopen(argv[1], "rb");
	for (;;) {
		int c = fgetc(f);
		if (c == EOF)
			break;

		switch (c) {
		case 'A' ... 'Z':
		case 'a' ... 'z':
			ungetc(c, f);
			handle_ident(f);
			break;
		case '"':
			fputc(c, stdout);
			handle_string(f);
			break;
		case ';':
			if (function) {
				printf(" __asm(\"%s\")", function_name);
				function = 0;
			}
			fputc(';', stdout);
			break;
		default:
			fputc(c, stdout);
			break;
		}
	}
}
