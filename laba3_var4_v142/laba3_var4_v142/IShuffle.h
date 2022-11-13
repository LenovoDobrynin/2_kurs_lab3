#pragma once

class IShuffle {
	virtual void shuffle(int left, int right) = 0;
	virtual void shuffle() = 0;
};