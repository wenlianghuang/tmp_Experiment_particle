import numpy as np 
#import tensorflow as tf

def next_batch(num,tmp,data,labels):
    '''
    Return a total of `num` random samples and labels. 
    '''
    idx = np.arange(0 , 100)
    #np.random.shuffle(idx)
    
    i_plum = tmp*num;
    i_plum_plum = (tmp+1) * num
    #print(tmp*num)
    idx = idx[i_plum:i_plum_plum]
    #print(idx)
    #print(idx)
    data_shuffle = [data[ i] for i in idx]
    labels_shuffle = [labels[ i] for i in idx]

    return np.asarray(data_shuffle), np.asarray(labels_shuffle)

Xtr,Ytr = np.arange(100,200),np.arange(0,100).reshape(10,10)
np.random.shuffle(Xtr)
#print(Ytr)
total = 100
batch_size = 5
total_batch = total/batch_size
tmp = 0
for i in range(total_batch):
    
    sub_Xtr,sub_Ytr = next_batch(5,i,Xtr,Ytr)
    tmp +=1
    #print(sub_Xtr)
    #print(sub_Ytr)

