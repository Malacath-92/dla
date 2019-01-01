#include "units.h"
#include "literals.h"
#include "vector.h"

int main() {
	using namespace dla;
	using namespace literals;
	using namespace int_literals;

	auto gravity_not_const = vec(0_m_s2, 0_m_s2, -9.81_m_s2);
	gravity_not_const *= 1.0f;
}