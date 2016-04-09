#include <linux/module.h>
#include <linux/slab.h>
#include "cs_table.h"

cs_table_t *cs_table_alloc(unsigned int size)
{
	cs_table_t *new_table;

	new_table = kmalloc(sizeof(cs_table_t), GFP_ATOMIC);
	if (new_table == NULL) return NULL;

	new_table->table_head = kzalloc(sizeof(cs_table_entry_t) * size, 
			GFP_ATOMIC);
	if (new_table->table_head == NULL) {
		kfree(new_table);
		return NULL;
	}

	return new_table;
} /* cs_table_alloc */

void cs_table_dealloc(cs_table_t *p_table)
{
	if (p_table == NULL) return;
	if (p_table->table_head != NULL)
		kfree(p_table->table_head);
	kfree(p_table);
} /* cs_table_dealloc */

cs_table_entry_t *cs_table_get_entry(cs_table_t *p_table, unsigned int index)
{
	if (p_table == NULL) return NULL;
	if (p_table->table_head == NULL) return NULL;
	return &p_table->table_head[index];
} /* cs_table_get_entry */

