open DomUtils;
open Geometry;

let canvas = getElementById("screen");
let canvasWidth = float_of_int(elementWidth(canvas));
let canvasHeight = float_of_int(elementHeight(canvas));

let screen = getContext2d(canvas);

let inversionCentre = (canvasWidth /. 4., canvasHeight /. 4.);
let inversionCircumference = {centre: inversionCentre, radius: 120.};

type state = {
  points: list(point),
  circumferences: list(circumference),
};

type mouseControls = {
  mutable pressed: bool,
  mutable position: point,
};

let draw = (state, canvas) => {
  Draw.clear(canvas);
  let ctx = getContext2d(canvas);
  List.iter(p => Draw.point(p, ctx), state.points);
  List.iter(
    p =>
      Draw.point(
        inverseOfPoint(inversionCircumference, p),
        ~color="red",
        ctx,
      ),
    state.points,
  );
  List.iter(c => Draw.circumference(c, ctx), state.circumferences);
};

let addTo = (state, point) => {...state, points: [point, ...state.points]};

let computeNextState = (state, mouseControls) => {
  mouseControls.pressed ? addTo(state, mouseControls.position) : state;
};

let rec drawingLoop = (state, mouseControls, canvas, _) => {
  let nextState = computeNextState(state, mouseControls);
  draw(nextState, canvas);
  requestAnimationFrame(drawingLoop(nextState, mouseControls, canvas));
};

let initialState = {
  points: [inversionCentre],
  circumferences: [inversionCircumference],
};

let mouseControls = {pressed: false, position: (0., 0.)};

addEventListener(canvas, "mousedown", _ => mouseControls.pressed = true);

addEventListener(canvas, "mouseup", _ => mouseControls.pressed = false);

addEventListener(canvas, "mousemove", e =>
  mouseControls.position = getCursorCoords(canvas, e)
);

drawingLoop(initialState, mouseControls, canvas, 0);