open DomUtils;
open Geometry;

let defaultColor = "black";

let setDefaultStrokeStyle = ctx => setStrokeStyle(ctx, defaultColor);
let setDefaultFillStyle = ctx => setFillStyle(ctx, defaultColor);

let circumference = ({centre, radius}, ~color=defaultColor, ctx) => {
  let (c1, c2) = centre;
  setStrokeStyle(ctx, color);
  beginPath(ctx);
  arc(ctx, c1, c2, radius, 0., pi *. 2., true);
  stroke(ctx);
  setDefaultStrokeStyle(ctx);
};

let segment = (((a1, a2), (b1, b2)), ~color=defaultColor, ctx) => {
  setStrokeStyle(ctx, color);
  beginPath(ctx);
  moveTo(ctx, a1, a2);
  lineTo(ctx, b1, b2);
  stroke(ctx);
  setDefaultStrokeStyle(ctx);
};

let point = ((p1, p2), ~color=defaultColor, ctx) => {
  setFillStyle(ctx, color);
  beginPath(ctx);
  arc(ctx, p1, p2, 1., 0., pi *. 2., true);
  fill(ctx);
  setDefaultFillStyle(ctx);
};

let clear = canvas =>
  clearRect(
    getContext2d(canvas),
    0,
    0,
    elementWidth(canvas),
    elementHeight(canvas),
  );