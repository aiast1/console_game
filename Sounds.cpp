#include "Declare.h"


void footstep() {
	PlaySound(TEXT("footstep.wav"), NULL, SND_FILENAME | SND_ASYNC );
}

void background_music() {
	PlaySound(TEXT("background_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
