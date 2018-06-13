/*
 * MemoryManager.h
 *
 *  Created on: 04/03/2012
 *      Author: Llopis
 *      Translated: Sergio Galvez Rojas
 */

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#define MAX 99


	typedef struct T_Node* T_handler;

	struct T_Node {
			unsigned start;
			unsigned end;
			T_handler next;
		};

// Creates the required structure to manage the available memory
	void Create(T_handler* handler) {

		*handler = (T_handler)malloc(sizeof(struct T_Node));

		(*handler)->start = 0;
		(*handler)->end = MAX;
		(*handler)->next = NULL;

	}

// Frees the required structure
	void Destroy(T_handler* handler) {

		T_handler aux;

		while((*handler)->next != NULL) {

			aux = *handler;

			handler = (*handler)->next;

			free(aux);

		}

	}

/* Returns in "ad" the memory address where the required block of memory with length "size" starts.
 * If this operation finishes successfully then "ok" holds a TRUE value; FALSE otherwise.
 */
	void Allocate(T_handler* handler, unsigned size, unsigned* ad, unsigned* ok) {



	}

/* Frees a block of memory with length "size" which starts at "ad" address.
 * If needed, can be assumed to be a previous allocated block
 */
	void Deallocate(T_handler* handler, unsigned size ,unsigned ad) {

		T_handler aux, prev, ptr;

		prev = NULL;
		ptr = *handler;

		while(ptr != NULL && ptr->start<ad) {

			prev = ptr;
			ptr = ptr->next;

		}

		if(ptr->start == ad) {

			aux = (T_handler)malloc(sizeof(struct T_Node));
			aux->start = ad;
			aux->end = MAX;
			aux->next = *handler;
			*handler = aux;

		} else {

			aux = (T_handler)malloc(sizeof(struct T_Node));
			aux->start = ad;
			aux->end = MAX;
			aux->next = ptr;
			prev->next = aux;

		}

		MergeAdjacent(handler);

	}

	void MergeAdjacent(T_handler* handler) {



	}

/* Shows the current status of the memory */
	void Show (T_handler handler) {

		printf("Memory state:\n");
		while((*handler) != NULL) {

			printf("Free block: start = %d, end = %d\n", handler->start, handler->end);

		}

	}


#endif /* MEMORYMANAGER_H_ */
