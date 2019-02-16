// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Geometry$Inversion = require("./Geometry.bs.js");

var defaultColor = "black";

function setDefaultStrokeStyle(ctx) {
  ctx.strokeStyle = defaultColor;
  return /* () */0;
}

function setDefaultFillStyle(ctx) {
  ctx.fillStyle = defaultColor;
  return /* () */0;
}

function circumference(param, $staropt$star, ctx) {
  var centre = param[/* centre */0];
  var color = $staropt$star !== undefined ? $staropt$star : defaultColor;
  ctx.strokeStyle = color;
  ctx.beginPath();
  ctx.arc(centre[0], centre[1], param[/* radius */1], 0, Geometry$Inversion.pi * 2, true);
  ctx.stroke();
  ctx.strokeStyle = defaultColor;
  return /* () */0;
}

function segment(param, $staropt$star, ctx) {
  var match = param[1];
  var match$1 = param[0];
  var color = $staropt$star !== undefined ? $staropt$star : defaultColor;
  ctx.strokeStyle = color;
  ctx.beginPath();
  ctx.moveTo(match$1[0], match$1[1]);
  ctx.lineTo(match[0], match[1]);
  ctx.stroke();
  ctx.strokeStyle = defaultColor;
  return /* () */0;
}

function point(param, $staropt$star, ctx) {
  var color = $staropt$star !== undefined ? $staropt$star : defaultColor;
  ctx.fillStyle = color;
  ctx.beginPath();
  ctx.arc(param[0], param[1], 1, 0, Geometry$Inversion.pi * 2, true);
  ctx.fill();
  ctx.fillStyle = defaultColor;
  return /* () */0;
}

exports.defaultColor = defaultColor;
exports.setDefaultStrokeStyle = setDefaultStrokeStyle;
exports.setDefaultFillStyle = setDefaultFillStyle;
exports.circumference = circumference;
exports.segment = segment;
exports.point = point;
/* Geometry-Inversion Not a pure module */
