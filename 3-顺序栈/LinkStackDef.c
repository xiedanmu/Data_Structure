#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "LinkStackDef.h"

//链栈：入栈，出栈，求栈顶的时间复杂度都是O(1)，不受顺序栈必须预估空间大小的限制

StackNodePtr MakeNode(StackEntry *item) {
	StackNodePtr np=(struct Node*)malloc(sizeof(struct Node));
	np->Entry = *item;
	return np;
}

Status Stack_Push(StackPtr s, StackEntry *item) {
	Status outcome = success;
	StackNodePtr np = MakeNode(*item);
	if (np == NULL) {
		outcome = overflow;
	}
	else {
		np->next = s->top;
		s->top = np;
	}
}

Status Stack_Pop(StackPtr s, StackEntry *item) {
	Status outcome = success;
	StackNodePtr x = s->top->next;
	if (x->Entry == NULL) {
		outcome = underflow;
	}
	else {
		StackNodePtr np = s->top;
		s->top = np->next;
		*item = np->Entry;
		free(np);
	}
	return outcome;
}

Status Stack_Empty(StackPtr s) {

}

Status Stack_Top(StackPtr s, StackEntry *item){
	Status outcome = success;
	StackNodePtr x = s->top->next;
	if (x->Entry == NULL) {
		outcome = underflow;
	}
	else {
		*item = s->top->Entry;
	}
}

