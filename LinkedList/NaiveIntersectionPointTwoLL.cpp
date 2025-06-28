/*
 *
 * Two singly linked lists forming a Y shaped list.
 * Get the point where two linked list merge.
 *
 * Naive Solution:
 * 	requires modifications to basic linked list.
 * 	Have a visited flag with each node.
 * 	Traverse the first linked list and keep marking visited nodes.
 * 	Traverse the second linked list, If we see a visited node again then there is an intersection point, return the intersecting node.
 * 	Works in O(m+n) but requires additional information with each node.
 *
 * Implemented into a hash.
 * Traverse the first linked list and store the addresses of visited nodes in a hash. Now traverse the second linked list and if we see an address that already exists in the hash then return the intersecting node.
 *
 */



