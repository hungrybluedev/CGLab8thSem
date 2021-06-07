#include <graphics.h>
#include <stdlib.h>

void drawLine(int x0, int y0, int x1, int y1) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int x = x0;
  int y = y0;
  int p = 2 * dy - dx;

  while (x < x1) {
    if (p >= 0) {
      putpixel(x, y, 7);
      y++;
      p += 2 * dy - 2 * dx;
    } else {
      putpixel(x, y, 7);
      x++;
      p += 2 * dy;
    }
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
