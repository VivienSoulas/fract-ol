use "make" to make fractol

use "./fractol <max_iteration> <length> <height> <arg>" to run program
	possible args : m, j, p, o, i

use key m to switch to Mandelbrot
use key j to switch to Julia preset 1
use key p to switch to Julia preset 2
use key o to switch to Julia preset 3
use key i to switch to Julia preset 4
	changing between fractal will reset initial parameters

use key r to reset zoom, max_iteration and colours

use mouse wheel to zoom in and out (zoom * 2)
use key w to increase max_iteration (+5)
use key s to decrease max_iteration (-5)
use key b, g and t to change colours
use arrows to move within the fract'ol
use key esc to close window



 // TO DO \\
zoom that follows the pointer
code extra fractal
take care of resizing window ?


 / ! \ not to self / ! \
initialise at
red = 0
green = 0
blue = 0
will initialise a black window but the colours will be true and will change with the first colours change
(key b will be blue, g green and t red)
colours aren't true with current version because of the division by num.it (but it is needed for the fractal/gradiant effect)
