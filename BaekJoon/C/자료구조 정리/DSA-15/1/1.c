#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int l_thread; //is leftt link thread?
	struct TreeNode *left;
	int data;
	int r_thread; //is right link thread?
	struct TreeNode  *right;

} TreeNode;


//
TreeNode *find_successor(TreeNode *p)
{
	TreeNode *q = p->right;
	if (! p->r_thread )
		while (!q->l_thread) q = q->left;
	return q;
}

main()
{
//		     10
//	     20		  30
//   40	   50   60     70
// 80   90

	TreeNode *q;
	int cnt=0;

	TreeNode n1 = { 0, NULL, 10, 0, NULL };
	TreeNode n2 = { 0, NULL, 20, 0, NULL };
	TreeNode n3 = { 0, NULL, 30, 0, NULL };
	TreeNode n4 = { 0, NULL, 40, 0, NULL };
	TreeNode n5 = { 1, NULL, 50, 1, NULL };
	TreeNode n6 = { 1, NULL, 60, 1, NULL };
	TreeNode n7 = { 1, NULL, 70, 1, NULL };
	TreeNode n8 = { 1, NULL, 80, 1, NULL };
	TreeNode n9 = { 1, NULL, 90, 1, NULL };

	TreeNode head = { 0, &n1, -999, 0, &head };

	n1.left  = &n2;
	n1.right = &n3;
	n2.left  = &n4;
	n2.right = &n5;

	n3.left  = &n6;
	n3.right = &n7;
	n4.left  = &n8;
	n4.right = &n9;


	n5.left = &n2;
	n5.right = &n1;
	n6.left = &n1;
	n6.right = &n3;

	n7.left = &n3;
	n7.right = &head;
	n8.left = &head;
	n8.right = &n4;

	n9.left = &n4;
	n9.right = &n2;

	printf("head node : (%p, %2d, %3d, %2d, %p) \n", head.left, head.l_thread, head.data, head.r_thread, head.right);
	q = &head;
	do
	{
		q = find_successor(q);
		if (q != &head) 
			printf("(%p, %2d, %3d, %2d, %p) ", q->left, q->l_thread, q->data, q->r_thread, q->right);
		cnt++;
		if (!(cnt % 2))
			printf("\n");
	} while (q != &head);

}