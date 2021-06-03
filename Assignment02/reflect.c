#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_vertical(int h, int d) {
  int max_dist = h - 2;
  for (int i = 0; i < h; i++) {
    if (i == 0 || i == h - 1) {
      printf("N");
      for (int j = 0; j < max_dist; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < d; j++) {
        printf(" ");
      }
      printf("|");
      for (int j = 0; j < d; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < max_dist; j++) {
        printf(" ");
      }
      printf("N");
    } else {
      printf("N");
      for (int j = 1; j < i; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < h - i - 2; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < d; j++) {
        printf(" ");
      }
      printf("|");
      for (int j = 0; j < d; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < h - i - 2; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 1; j < i; j++) {
        printf(" ");
      }
      printf("N");
    }
    printf("\n");
  }
}

void print_horizontal(int h, int d) {
  int max_dist = h - 2;
  for (int i = 0; i < h; i++) {
    if (i == 0 || i == h - 1) {
      printf("N");
      for (int j = 0; j < max_dist; j++) {
        printf(" ");
      }
      printf("N");
    } else {
      printf("N");
      for (int j = 1; j < i; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < h - i - 2; j++) {
        printf(" ");
      }
      printf("N");
    }
    printf("\n");
  }
  for (int i = 0; i < d; i++) {
    printf("\n");
  }
  for (int j = 0; j < h; j++) {
    printf("-");
  }
  for (int i = 0; i <= d; i++) {
    printf("\n");
  }
  for (int i = h - 1; i >= 0; i--) {
    if (i == 0 || i == h - 1) {
      printf("N");
      for (int j = 0; j < max_dist; j++) {
        printf(" ");
      }
      printf("N");
    } else {
      printf("N");
      for (int j = 1; j < i; j++) {
        printf(" ");
      }
      printf("N");
      for (int j = 0; j < h - i - 2; j++) {
        printf(" ");
      }
      printf("N");
    }
    printf("\n");
  }
}

int main() {
  int height, distance;
  char axis_type = '\n';
  bool vertical;
  printf("Enter height : ");
  scanf("%d", &height);

  if (height < 3) {
    printf("Height must be at least 3.\n");
    return EXIT_FAILURE;
  }

  printf("\nEnter V for vertical axis, H for horizontal axis : ");
  while (axis_type == '\n') {
    scanf("%c", &axis_type);
  }
  switch (axis_type) {
  case 'V':
  case 'v':
    vertical = true;
    break;
  case 'H':
  case 'h':
    vertical = false;
    break;
  default:
    printf("Unrecognised character: '%c'\n", axis_type);
    return EXIT_FAILURE;
  }

  printf("\nEnter distance from axis : ");
  scanf("%d", &distance);
  if (distance < 0) {
    printf("Distance cannot be negative.\n");
    return EXIT_FAILURE;
  }

  if (vertical) {
    print_vertical(height, distance);
  } else {
    print_horizontal(height, distance);
  }

  return EXIT_SUCCESS;
}