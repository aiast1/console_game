#include "Declare.h"


void footstep() {
	PlaySound(TEXT("footstep.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_PURGE);
}