/* FILE main.c
 *    Test the functionality of the avl_bag implementation.
 * Author: Francois Pitt, March 2012.
 */

/******************************************************************************
 *  Types and Constants.                                                      *
 ******************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bag.h"

/******************************************************************************
 *  Function declarations.                                                    *
 ******************************************************************************/

/* FUNCTION bag_print -- "hidden" function in avl_bag.c for debugging. */
extern // not strictly necessary -- it's the default for function
void bag_print(const bag_t *bag, int indent, void (*print)(bag_elem_t));

/******************************************************************************
 *  Function definitions.                                                     *
 ******************************************************************************/

/* FUNCTION float_cmp
 *    Compare two (void *) values that point to floats and return -1, 0, or +1
 *    as to the first value is less than, equal to, or greater than the second.
 * Parameters and preconditions:
 *    a != NULL: pointer to the first float to compare
 *    b != NULL: pointer to the second float to compare
 * Return value:
 *    -1 if *a < *b; 1 if *a > *b; 0 if *a == *b
 * Side-effects:  none
 */
static
int float_cmp(bag_elem_t a, bag_elem_t b)
{
    return *(float *) a < *(float *) b ? -1
         : *(float *) a > *(float *) b; /* ? 1 : 0 would be redundant */
}

/* FUNCTION float_print
 *    Print a single float (passed in as a bag_elem_t) with a space in front.
 * Parameters and preconditions:
 *    e != NULL: pointer to a float
 * Return value:  none
 * Side-effects:
 *    the floating-point value of e is printed to stdout, preceded by a space
 */
static
void float_print(bag_elem_t e)
{
    printf(" %g", *(float *) e);
}

/* FUNCTION main
 *    Run some tests of the functionality of the bst_bag implementation.
 * Parameters and preconditions:  none
 * Return value:  exit status
 * Side-effects:  the main program is executed
 */
int main(void)
{
    size_t i;
    float elts[] = {3.2, 3.1, 3, 10, 11, 4, 1, 0, 0.2, 5, 0.4, 2};
    float bad_elts[] = {56, 0.001, 0.2000001, 75, 50, -1, 0.1};

    /* Create a new bag. */
    bag_t *b1 = bag_create(float_cmp);
    bag_t *b2 = bag_create(float_cmp);
    for(i=0; i<12; i++){
        bag_insert(b1, &elts[i]);
        bag_insert_norot(b2, &elts[i]);
    }
    bag_print(b1, 8, float_print); printf("\n\n\n\n"); // bag_print(b2, 8, float_print);
    printf("%d %d\n", is_avl_tree(b1), is_avl_tree(b2));
    bag_remove_2(b1, &elts[0]);
    bag_print(b1, 8, float_print);
    printf("\n%d\n", is_avl_tree(b1));


    return 0;
}