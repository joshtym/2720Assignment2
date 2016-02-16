Simple program that utilizes the allegro libraries to bounce shapes off the
sides of a display. The way this was utilized was by defining shapes
which had the common attributes: an origin, a minimum point, a maximum
point and a speed vector. Once a shape hit a wall, then its speed
vector was reversed. IE, if I hit the outer width wall, then the x factor 
of the vector would be reflected.

Note that there are two compilations with this. One is the regular one
called animatedShapes and is easily compiled using make animatedShapes

The other is purely for testing and is defined as testShapes. IE
make testShapes will yield this one for testing (Insert Portal 2 reference
here)

Regards,
Josh T
