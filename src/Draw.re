open Dom;

let pi = acos(-1.);

type point = {
  x: float,
  y: float,
};

let circle = ({x, y}, r, ctx) => {
  beginPath(ctx);
  arc(ctx, x, y, r, 0., pi *. 2., true);
  closePath(ctx);
  stroke(ctx);
};