#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#include "RectSprites.h"
#include "SDL/include/SDL_log.h"
#define MAX_FRAMES 100

class Animation
{
public:
	bool loop = true;
	float speed = 1.0f;
	RectSprites frames[MAX_FRAMES];
	int currentPos = 0;
	int currentDisPos = 0;
	int AnimationDamage;

private:
	float current_frame = 0;
	float current_displacement_frame = 0;
	int last_frame = 0;
	int loops = 0;

public:
	bool PushBack(const SDL_Rect& rect, int offsetX = 0, int offsetY = 0, int numFrames = 1, iPoint displacement = { 0, 0 }, iPoint HitColiderPosition = {-10, -10})
	{
		iPoint offset{ offsetX,offsetY};
		for (int i = 0; i < numFrames; i++)
		{

			frames[last_frame].rect = rect;
			frames[last_frame].offset.x = offset.x;
			frames[last_frame].offset.y = offset.y;
			frames[last_frame].displacement = displacement;
			frames[last_frame].DamagePosition = HitColiderPosition;
			last_frame++;
		}
		return true;

	}

	RectSprites& GetCurrentFrame()
	{
		current_frame += speed;
		if (current_frame >= last_frame) {
			current_frame = (loop) ? 0.0f : last_frame - 1;
			loops++;
		}

		currentPos = (int)current_frame;
		return frames[currentPos];
	}
	iPoint& GetDisplacementFrame() {
		current_displacement_frame += speed;
		if (current_displacement_frame >= last_frame) {
			current_displacement_frame = (loop) ? 0.0f : last_frame - 1;
			loops++;
		}

		currentDisPos = (int)current_displacement_frame;
		return frames[currentDisPos].displacement;
	}

	bool Finished() const {
		return loops > 0;
	}
	int GetCurrentFramePos() {
		return currentPos;
	}

	int GetDisplacementFramePos(){
		return currentDisPos;
	}
	void ResetCurrentFrame() {
		current_frame = 0;
		currentPos = 0;

	}
	void ResetDisplacement() {
		currentDisPos = 0;
		current_displacement_frame = 0;
	}
	int GetLastFrame() {
		return last_frame;
	}

};

#endif