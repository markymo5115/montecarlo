#include <PayOff1.h>
#include <algorithm>

using namespace std;

PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
	:
		Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

double PayOff::operator ()(double spot) const
{
	switch (TheOptionsType)
	{
		case call :
			return max(spot-Strike, 0.0);

		case put:
			return max(Strike-spot, 0.0);

		default:
			throw("unkown option type found. ");
	}
}
