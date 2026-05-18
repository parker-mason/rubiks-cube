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
void counterclockwise(struct side* , size_t );

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
	/*       ---   TESTING   ----
	struct side s = {0, 2, 2, 3, 2, 2, 2, 2, 2};
	const int s_length = 9;
	print_side(s, s_length);
	clockwise(&s, s_length);
	print_side(s, s_length);	
	counterclockwise(&s, s_length);
	print_side(s, s_length);	
	*/

	struct side cube[6];
					//  # of colors
	for (int i = 0; i < 6; i++) {
		cube[i] = (struct side) {i, i, i, i, i, i, i, i, i};
	}
	for (int i = 0; i < 6; i++) {
		print_side(cube[i].faces, 9);
	}
}

void clockwise(struct side* s, size_t length) {
	int current, previous;
	for (int i = 1; i < length; i++) { // s[0] is the centre
		if (i == 1) {
			previous = s->faces[length-1];
		}
		current = s->faces[i];
		s->faces[i] = previous;
		previous = current;
	}
}

void counterclockwise(struct side* s, size_t length) {
	int current, previous;
	for (int i = length - 1; i > 0; i--) {
		if (i == length - 1) {
			previous = s->faces[1];
		}
		current = s->faces[i];
		s->faces[i] = previous;
		previous = current;
	}
}
