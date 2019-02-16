open Dom;

let pi = acos(-1.);

type point = {
  x: float,
  y: float,
};

let circle = ({x, y}, r, ctx) => {
  beginPath(ctx);
  arc(ctx, x, y, r, 0., pi *. 2., true);
  stroke(ctx);
};

let segment = (from, to_, ctx) => {
  beginPath(ctx);
  moveTo(ctx, from.x, from.y);
  lineTo(ctx, to_.x, to_.y);
  stroke(ctx);
};