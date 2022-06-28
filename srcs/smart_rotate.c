#include "push_swap.h"

//Rotate or reverse rotate next element to push.
void	smart_rotate(char ch, t_stack *stack, int target, int bigger)
{
	int	target_value;

	target_value = stack->arr[target];

	while (stack->arr[0] != target_value)
	{
		if (target > ((stack->size) / 2 + 1))
			rev_rotate(ch, stack);
		else
		{
			(void)bigger;
		//	if (bigger && stack->arr[1] > stack->arr[0] && stack->arr[1] == target_value) 
		//		swap(ch, stack);
		//	else if (!bigger && stack->arr[1] < stack->arr[0] && stack->arr[1] == target_value)
		//		swap(ch, stack);
		//	else
				rotate(ch, stack);
		}
	}
}