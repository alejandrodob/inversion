open DomUtils;
open Geometry;

let defaultColor = "black";

let setDefaultStrokeStyle = ctx => setStrokeStyle(ctx, defaultColor);
let setDefaultFillStyle = ctx => setFillStyle(ctx, defaultColor);

let circumference = ({centre, radius}, ~color=defaultColor, canvas) => {
  let (c1, c2) = centre;
  let ctx = getContext2d(canvas);
  setStrokeStyle(ctx, color);
  beginPath(ctx);
  arc(ctx, c1, c2, radius, 0., pi *. 2., true);
  stroke(ctx);
  closePath(ctx);
  setDefaultStrokeStyle(ctx);
};

let segment = (((a1, a2), (b1, b2)), ~color=defaultColor, canvas) => {
  let ctx = getContext2d(canvas);
  setStrokeStyle(ctx, color);
  beginPath(ctx);
  moveTo(ctx, a1, a2);
  lineTo(ctx, b1, b2);
  stroke(ctx);
  closePath(ctx);
  setDefaultStrokeStyle(ctx);
};

let line = (((a1, a2), (b1, b2)), ~color=defaultColor, canvas) => {
  let ctx = getContext2d(canvas);
  let canvasWidth = elementWidth(canvas);
  let canvasHeight = elementHeight(canvas);
  let (d1, d2) = (b1 -. a1, b2 -. a2);
  let canvasSize = distance((0., 0.), (canvasWidth, canvasHeight));
  setStrokeStyle(ctx, color);
  beginPath(ctx);
  moveTo(ctx, a1 -. d1 *. canvasSize, a2 -. d2 *. canvasSize);
  lineTo(ctx, a1 +. d1 *. canvasSize, a2 +. d2 *. canvasSize);
  stroke(ctx);
  closePath(ctx);
  setDefaultStrokeStyle(ctx);
};

let point = ((p1, p2), ~color=defaultColor, canvas) => {
  let ctx = getContext2d(canvas);
  setFillStyle(ctx, color);
  beginPath(ctx);
  arc(ctx, p1, p2, 1., 0., pi *. 2., true);
  fill(ctx);
  closePath(ctx);
  setDefaultFillStyle(ctx);
};

let clear = canvas =>
  clearRect(
    getContext2d(canvas),
    0.,
    0.,
    elementWidth(canvas),
    elementHeight(canvas),
  );