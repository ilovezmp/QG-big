//队列的结构体
typedef struct Aqueue
{
    void *data[MAXQUEUE];//泛型的数据域
    int front;
    int rear;
    size_t length;//队列的长度
    //一个节点可以存放不同的数据类型
    int type[MAXQUEUE];
}AQueue;
//初始化对列
void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        //不知道用户想放入的数据类型大小，所以任给超过float8字节的预留数据
        Q->data[i] = (void *)malloc(101);
	Q->front = Q->rear = 0;
}
//销毁队列，整个队列都没了
void DestoryAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}
//判断队列是否未满
Status IsFullAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else
        return FALSE;
}
//判断是否为空
Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}
//访问队头
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);
    return TRUE;
}
int LengthAQueue(AQueue *Q)
    {
        return (Q->rear-Q->front+Q->length)%Q->length;
    }
//入队操作
Status EnAQueue(AQueue *Q, void *data)
{
    if (IsFullAQueue(Q))
    {
        printf("队列满了！不能再入队了！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        memcpy(Q->data[Q->front], data, 20);
        Q->rear = (Q->rear + 1) % Q->length;
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 20);
    Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}
//出队操作
Status popAQueue(AQueue *Q)
    {
    	if (IsEmptyAQueue(Q))
    	{
    		printf("队列是空的！出不了队！\n");
    		return FALSE;
    	}
        Q->front = (Q->front+1)%Q->length;
        return TRUE;
    }
//清空整个队列，但是还是有队列，只是没有元素了
void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0;
}
//遍历操作
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int typeData))
    {
        if(Q->data[0] == NULL)
        {
            printf("队列目前未初始化！请先初始化队列！\n");
            return FALSE;
        }
    	if (IsEmptyAQueue(Q))
    	{
    		printf("队列里面什么都没有!\n");
    		return FALSE;
    	}
    	int i = 0;
    	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
    		foo(Q->data[Q->front+i], Q->type[Q->front+i]);
    		i = (i + 1) % MAXQUEUE;
    	}
        return TRUE;
    }