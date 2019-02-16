open Dom;
open Draw;

let canvas = getElementById("screen");

let screen = getContext2d(canvas);

circle({x: 100., y: 100.}, 40., screen);

segment({x: 100., y: 100.}, {x: 300., y: 300.}, screen);