#include <graphics.h>
#include <stdlib.h>

void drawLine(int x0, int y0, int x1, int y1) {
  float dx = (float)(x1 - x0);
  float dy = (float)(y1 - y0);
  float step = dx >= dy ? dx : dy;

  dx /= step;
  dy /= step;

  float x = x0;
  float y = y0;
  int i = 0;

  while (i < step) {
    putpixel(x, y, 7);
    x += dx;
    y += dy;
    i++;
  }
}

int main() {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "");
  errorcode = graphresult();

  if (errorcode != grOk) {
    printf("An error occurred: %s\n", grapherrormsg(errorcode));
    printf("Press any key to stop: ");
    getch();

    return EXIT_FAILURE;
  }

  int x0, y0, x1, y1;
  print("Enter value for x0: ");
  scanf("%d", &x0);
  print("Enter value for y0: ");
  scanf("%d", &y0);
  print("Enter value for x1: ");
  scanf("%d", &x1);
  print("Enter value for y1: ");
  scanf("%d", &y1);

  drawLine(x0, y0, x1, y1);

  printf("Press any key to continue: ");
  getch();

  closegraph();

  return EXIT_SUCCESS;
}
