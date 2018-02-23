/**
 */
#ifndef UL_DRDICT_H
#define UL_DRDICT_H


typedef struct{
	int	hash_num;	// number of hash
	int	node_num;	// number of nodes
	int	cur_code;	// current minimum unused term code

	Sdict_bhash	*hash;	// hash
	
	Sdict_bnode_block	*nblock;	//first block
	Sdict_bnode_block	*cur_nblock;	//current block
	Sdict_bnode		*cur_node;	//current node
	Sdict_bnode *reclaim_node;
	int			node_avail;	//avail node_num in cur_b
} Sdict_reclaim;


 
/**
 *  �����ֵ�
 *  
 * - ��NULL   �ɹ�
 * - NULL     ʧ��
 */ 
Sdict_reclaim *dr_creat( int hash_num, int now_code );

 
/**
 *  �ͷ��ֵ���Դ
 *  
 * - 1         �ɹ�
 * - other     ʧ��
 */ 
int dr_del( Sdict_reclaim *pdb);



/**
 *  �����ֵ����
 *  
 * - 1         �ɹ�
 * - 0         ʧ��(������)
 * - other     ����
 * - SEEK ���ң�����ҵ�����pnode�����ҵ��Ľڵ���Ϣ����������1�����û�ҵ�����������0
 * - MOD  �޸ģ������Ŀ���ֵ��У��޸Ľڵ㣬��������1�����򣬷���0
 * - DEL  ɾ�����������ֵ���ɾ���Ľڵ�
 * - ADD  ������������ֵ��У�freq++�����ҷ��ؽ����Ϣ����������ֵ��У������½ڵ㣬����ʼ���ڵ㣨code=cur_code, freq=1,low_weight=0�������½ڵ����Ϣ��
 */
int dr_op1( Sdict_reclaim *pdb, Sdict_snode *pnode, Eop_method op_method);

#endif