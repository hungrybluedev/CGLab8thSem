#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct context_struct {
  // The limits of the viewport for plotting
  const double y_min;
  const double y_max;
  const double x_min;
  const double x_max;
  // The size of the viewport in the terminal in terms of character
  // widths/heights
  const size_t h;
  const size_t w;
  char *buffer;
} Context;

static int interp_x(double x, Context ctx) {
  return (int)round((x - ctx.x_min) / (ctx.x_max - ctx.x_min) * ctx.w);
}

static int interp_y(double y, Context ctx) {
  return ctx.h - 1 -
         (int)round((y - ctx.y_min) / (ctx.y_max - ctx.y_min) * ctx.h);
}

static size_t mix(Context ctx, size_t row, size_t col) {
  return row * ctx.w + col;
}

static double to_rad(double deg) { return deg * M_PI / 180; }

void plot_axes(Context ctx) {
  size_t zx = interp_x(0, ctx);
  size_t zy = interp_y(0, ctx);
  // Plot the X axis
  for (size_t col = 0; col < ctx.w; col++) {
    ctx.buffer[mix(ctx, zy, col)] = '#';
  }
  // Plot the Y axis
  for (size_t row = 0; row < ctx.h; row++) {
    ctx.buffer[mix(ctx, row, zx)] = '#';
  }
}
void plot_text(Context ctx, char *text, double x, double y, double x_off,
               double y_off) {

  size_t len = strlen(text);
  size_t index = 0;
  size_t px = interp_x(x, ctx) + x_off;
  size_t py = interp_y(y, ctx) + y_off;

  while (index < len && px < ctx.w) {
    ctx.buffer[mix(ctx, py, px)] = text[index];
    index++;
    px++;
  }
}

void plot_curve(Context ctx) {
  const size_t N = 200;
  const double step = (ctx.x_max - ctx.x_min) / N;

  double x = ctx.x_min;

  for (size_t count = 0; count < N; count++, x += step) {
    double y = sin(to_rad(x));
    size_t px = interp_x(x, ctx);
    size_t py = interp_y(y, ctx);
    ctx.buffer[mix(ctx, py, px)] = '*';
  }
}

void plot_labels(Context ctx) {
  const size_t x_ticks = 12;
  const size_t y_ticks = 8;

  const double x_step = (360.0 - 0.0) / x_ticks;
  const double y_step = (+1.0 + 1.0) / y_ticks;

  char buf[5];

  // Labels along the X axis
  for (size_t x_count = 1; x_count <= x_ticks; x_count++) {
    double x = x_count * x_step;
    double y = 0;
    sprintf(buf, "%3.0f", x);
    plot_text(ctx, buf, x, y, 0, -1);
  }

  // Labels along the Y axis
  for (size_t y_count = 0; y_count <= y_ticks; y_count++) {
    double x = 0;
    double y = y_count * y_step - 1.0;
    sprintf(buf, "%+2.1f", y);
    plot_text(ctx, buf, x, y, -1, 0);
  }
}

void display(Context ctx) {
  for (size_t row = 0; row < ctx.h; row++) {
    for (size_t col = 0; col < ctx.w; col++) {
      putchar(ctx.buffer[row * ctx.w + col]);
    }
    printf("\n");
  }
}

int main() {
  Context ctx = {
      .y_min = -1.2,
      .y_max = +1.2,
      .x_min = -10.0,
      .x_max = +380.0,
      .h = 30,
      .w = 100,
  };

  ctx.buffer = malloc(ctx.h * ctx.w * sizeof(char));
  // Initialize the buffer with spaces.
  for (size_t i = 0; i < ctx.h * ctx.w; i++) {
    ctx.buffer[i] = ' ';
  }

  plot_axes(ctx);
  plot_curve(ctx);
  plot_labels(ctx);

  display(ctx);

  free(ctx.buffer);

  return EXIT_SUCCESS;
}