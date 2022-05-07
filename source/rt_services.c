#include <rt_services.h>

constraint_handler_t __sys_current_constraint_handler = NULL;

constraint_handler_t set_constraint_handler_s(constraint_handler_t handler)
{
	constraint_handler_t old;

	old = __sys_current_constraint_handler;

	__sys_current_constraint_handler = handler;
	return old;
}
