// The midi notes of a scale
var notes = [60, 62, 64, 65, 67, 69, 71, 80, 90, 100, 120];
var osc;

function setup() {
  createCanvas(1110, 480);

  // A triangle oscillator
  osc = new p5.TriOsc();
  // Start silent
  osc.start();
  osc.amp(0);
}

// A function to play a note
function playNote(note, duration) {
  osc.freq(midiToFreq(note));
  // Fade it in
  osc.fade(0.5, 0.2);

  // If we sest a duration, fade it out
  if (duration) {
    setTimeout(function () {
      osc.fade(0, 0.2);
    }, duration - 50);
  }
}

function draw() {
  // Draw a keyboard

  // The width for each key
  var w = width / notes.length;
  for (var i = 0; i < notes.length; i++) {
    var x = i * w;
    // If the mouse is over the key
    if (mouseX > x && mouseX < x + w && mouseY < height) {
      // If we're clicking
      if (mouseIsPressed) {
        fill(100, 255, 200);
        // Or just rolling over
      } else {
        fill(127);
      }
    } else {
      if (i % 2 == 0) {
        fill(1111);
      } else {
        fill(0000);
      }
    }

    // Draw the key

    rect(x, 0, w - 1, i % 2 ? height - 200 : height - 1);
    rect(x + 100, 0, w - 1, i % 2 ? height - 200 : height - 1);
  }
}

// When we click
function mousePressed() {
  // Map mouse to the key index
  var key = floor(map(mouseX, 0, width, 0, notes.length));
  playNote(notes[key]);
}

// Fade it out when we release
function mouseReleased() {
  osc.fade(0, 0.5);
}

function keyPressed() {
  switch (keyCode) {
    case 74:
      if (direction !== "right") {
        direction = "left";
      }
      break;
    case 76:
      if (direction !== "left") {
        direction = "right";
      }
      break;
    case 73:
      playNote(notes[0]);
      osc.fade(0, 0.5);
      break;
    case 75:
      if (direction !== "up") {
        direction = "down";
      }
      break;
  }
}
