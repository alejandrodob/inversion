open Dom;
open Geometry;

let canvas = getElementById("screen");
let canvasWidth = float_of_int(elementWidth(canvas));
let canvasHeight = float_of_int(elementHeight(canvas));

let screen = getContext2d(canvas);

let inversionCentre = (canvasWidth /. 4., canvasHeight /. 4.);
let inversionCircumference = {centre: inversionCentre, radius: 120.};
Draw.point(inversionCentre, screen);
Draw.circumference(inversionCircumference, screen);

let a = (245., 345.);
let a' = inverseOfPoint(inversionCircumference, a);
Draw.point(a, ~color="green", screen);
Draw.point(a', ~color="red", screen);

/* let s = ((20., 390.), (260., 163.));
   Draw.segment(s, ~color="blue", screen); */