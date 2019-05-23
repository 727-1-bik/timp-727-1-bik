#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
  int data;
  struct node * left;
  struct node * right;
  struct node * parent;
} node;

typedef struct tree
{
  struct node * root;
  int count;
} tree;

void init(tree * t)
{
    struct tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}

int find(tree* t, int value, node* n)
{
  struct node * n2;
  n2 = t->root;

  while (n2 != NULL)
  {
    if (n2->data == value)
    {
      n->data = n2->data;
      n->left = n2->left;
      n->right = n2->right;
      n->parent = n2->parent;
      return 0;
    } 
    else if (value > n2->data)
    {
      n2 = n2->right;
    } 
    else 
    {
      n2 = n2->left;
    }
  }
  return 1;
}

int insert(tree* t, int value)
{
  struct node * n, ** nn, * last_n = NULL;
  struct node * e_n;
  e_n = malloc(sizeof * e_n);
  if (find(t, value, e_n) == 0)
  {
    return 1;
  }
  nn = &t->root;
  n = t->root;
  while (true)
  {
    if (n == NULL) 
    {
      n = *nn = malloc(sizeof * n);
      if (n != NULL)
      {
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        n->parent = last_n;
        t->count++;
        return 0;
      } 
      else 
      {
        return 2;
      }
    }
    last_n = n;
    if (value > n->data)
    {
      nn = &n->right;
      n = n->right;
    } 
    else 
    {
      nn = &n->left;
      n = n->left;
    }
  }
  return 0;
}

int _remove(tree* t, int value)
{
  node * n = t->root;
  if (t->root == NULL)
  {
    return 1;
  }
  while (true)
  {
    if (n == NULL) 
    {
      break;
      return 1;
    } 
    else if (n->data == value)
    {
      break;
    } 
    else if (value > n->data)
    {
      n = n->right;
    } 
    else 
    {
      n = n->left;
    }
  }

  if ((n->left == NULL) && (n->right == NULL))
  {
    if (n->parent->right->data == n->data)
    {
      n->parent->right = NULL;
    } 
    else 
    {
      n->parent->left = NULL;
    }
  } 
  else if (n->right == NULL)
  {
    *n = *n->left;
  } 
  else if (n->left == NULL)
  {
    *n = *n->right;
  } 
  else 
  {
    node * search = n->right;
    int min_value;
    node *min;
    while (search != NULL)
    {
      min = search;
      min_value = search->data;
      search = search->left;
    }
    n->data = min->data;
    n = min;
    if ((n->left == NULL) && (n->right == NULL))
    {
      if (n->parent->right->data == n->data)
      {
        n->parent->right = NULL;
      } 
      else 
      {
        n->parent->left = NULL;
      }
    } 
    else if (n->right == NULL)
    {
      *n = *n->left;
    } 
    else 
    {
      *n = *n->right;
    }
  }
  t->count--;
  return 0;
}

int deepness(struct node * n, int deep)
{
  if (n == NULL)
  {
    return deep;
  }
  int d1 = deepness(n->left, deep + 1);
  int d2 = deepness(n->right, deep + 1);
  return (d1 > d2) ? d1 : d2;
}

void printNode(struct node * n, int current, int deep, int first)
{
  if (current == deep)
  {
      if (first > 0)
      {
        printf(" ");
      }
    if (n == NULL)
    {
      printf("_");
    } 
    else
    {
      printf("%d", n->data);
    }
  } 
  else if (n != NULL)
  {
    printNode(n->left, current + 1, deep, first);
    printNode(n->right, current + 1, deep, first + 1);
  } 
  else 
  {
    printNode(n, current + 1, deep, first);
    printNode(n, current + 1, deep, first + 1);
  }
}

void print(struct node * n)
{
  int m = deepness(n, 0);
  for (int i = 1; i <= m; i++)
  {
    printNode(n, 1, i, 0);
    printf("\n");
  }
}

void printTree(struct tree * t)
{
    print(t->root);
}

void dump(struct node * n)
{
  if (n != NULL)
  {
    printf("%d ", n->data);
    dump(n->left);
    dump(n->right);
  }
}

int removeMin(node* n)
{
  if (n->left == NULL)
  {
    n = n->right;
  }
  while(true)
  {
    if (n->left == NULL)
    {
      if ((n->left == NULL) && (n->right == NULL))
      {
        if (n->parent->right->data == n->data)
        {
          n->parent->right = NULL;
        } 
        else 
        {
          n->parent->left = NULL;
        }
      } 
      else if (n->right == NULL)
      {
        *n = *n->left;
      } 
      else 
      {
        *n = *n->right;
      }
      return n->data;
    } 
    else 
    {
      n = n->left;
    }
  }
}

int rotateRight(tree * t, node *x)
{
  node * y = x->left;
  if ((y != NULL) && (x != NULL))
  {
    x->left = y->right;
    if (y->right != NULL)
    {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != NULL)
    {
      if (x->parent->left == x)
      {
        x->parent->left = y;
      } 
      else 
      {
        x->parent->right = y;
      }
    }
    t->root = y;
    y->right = x;
    x->parent = y;
    return 0;
  } 
  else 
  {
    return 1;
  }
}

int rotateLeft(tree * t, node *x)
{
  node * y = x->right;
  if ((y != NULL) && (x != NULL))
  {
    x->right = y->left;
    if (y->left != NULL)
    {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != NULL)
    {
      if (x->parent->right == x)
      {
        x->parent->right = y;
      } 
      else 
      {
        x->parent->left = y;
      }
    }
    t->root = y;
    y->left = x;
    x->parent = y;
    return 0;
  } 
  else 
  {
    return 1;
  }
}


int main()
{
  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 4; i++)
  {
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  for (int i = 0; i < 3; i++)
  {
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  printTree(t);
  int m1;
  scanf("%d", &m1);
  struct node * n;
  n = malloc(sizeof * n);
  find(t, m1, n);
  if (n->parent != NULL)
  {
    printf("%d ", n->parent->data);
  } 
  else 
  {
    printf("_ ");
  }
  if (n->left != NULL)
  {
    printf("%d ", n->left->data);
  } 
  else 
  {
    printf("_ ");
  }
  if (n->right != NULL)
  {
    printf("%d\n", n->right->data);
  } 
  else 
  {
    printf("_\n");
  }
  int m2;
  scanf("%d", &m2);
  struct node * n2;
  n2 = malloc(sizeof * n2);
  int err = find(t, m2, n);
  if (err == 1)
  {
    printf("-\n");
  } 
  else 
  {
    if (n2->parent != NULL)
    {
      printf("%d ", n2->parent->data);
    } 
    else 
    {
      printf("_ ");
    }
    if (n2->left != NULL)
    {
      printf("%d ", n2->left->data);
    } 
    else 
    {
      printf("_ ");
    }
    if (n2->right != NULL)
    {
      printf("%d\n", n2->right->data);
    } 
    else 
    {
      printf("_\n");
    }
  }
  int m3;
  scanf("%d", &m3);
  _remove(t, m3);
  printTree(t);
  while (rotateLeft(t, t->root) != 1);
  printTree(t);
  while (rotateRight(t, t->root) != 1);
  printTree(t);
  printf("%d\n", t->count);
  printf("-\n");
  return 0;
}
