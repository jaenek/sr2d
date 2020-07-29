namespace sr2d {

Vector::Vector(float _x, float _y) {
	x = _x;
	y = _y;
}

float Vector::length() {
	return sqrtf(x*x+y*y);
}

}
