// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';


function getCursorCoords(elem, evt) {
  var rect = elem.getBoundingClientRect();
  return /* tuple */[
          evt.clientX - rect.left,
          evt.clientY - rect.top
        ];
}

exports.getCursorCoords = getCursorCoords;
/* No side effect */
