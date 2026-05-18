#include <stdio.h>
#include <stdlib.h>

struct side {
	int faces[9];
};

enum color_int {
	white = 0,
	orange,
	green,
	red,
	blue,
	yellow
};

char* color_str[6] = {"white", "orange", "green", "red", "blue", "yellow"};

void clockwise(struct side* , size_t );
void counterclockwise(struct side* , size_t);

char* color_convert(const int num) {
	return color_str[num];
}

void print_side(struct side s, size_t length) {
	for (int i = 0; i < length; i++) {
		printf("%s ", color_convert(s.faces[i]));
	}
	printf("\n");
}

int main() {
	struct side s = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	const int s_length = 9;
	for (int i = 0; i < 3; i++) {
		clockwise(&s, s_length);
		print_side(s, s_length);
	}
}

void clockwise(struct side* s, size_t length) {
	int current, previous;
	for (int i = 1; i < length; i++) {
		if (i == 1) {
			previous = s->faces[length-1];
		}
		current = s->faces[i];
		s->faces[i] = previous;
		previous = current;
	}
}

void counterclockwise(struct side*, size_t);