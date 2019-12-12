#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "HashDef.h"

int Hash(int key) {
	return key % SIZE;
}