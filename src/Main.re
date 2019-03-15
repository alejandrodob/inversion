open DomUtils;
open Geometry;

let inversionCentre = (125., 125.);
let inversionCircumference = {centre: inversionCentre, radius: 120.};

type state = {
  points: list(point),
  circumferences: list(circumference),
  lines: list(line),
};

type mouseControls = {
  mutable pressed: bool,
  mutable position: point,
};

let draw = (state, canvas) => {
  Draw.clear(canvas);
  List.iter(p => Draw.point(p, canvas), state.points);
  List.iter(
    p =>
      Draw.point(
        inverseOfPoint(inversionCircumference, p),
        ~color="red",
        canvas,
      ),
    state.points,
  );
  List.iter(c => Draw.circumference(c, canvas), state.circumferences);
  List.iter(l => Draw.line(l, canvas), state.lines);
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
  lines: [((0., 0.), (1., 1.)), ((15., 10.), (15., 9.))],
};

let mouseControls = {pressed: false, position: (0., 0.)};

let init = () => {
  let canvas = getElementById("screen");

  addEventListener(canvas, "mousedown", _ => mouseControls.pressed = true);

  addEventListener(canvas, "mouseup", _ => mouseControls.pressed = false);

  addEventListener(canvas, "mousemove", e =>
    mouseControls.position = getCursorCoords(canvas, e)
  );

  drawingLoop(initialState, mouseControls, canvas, 0);
};

init();