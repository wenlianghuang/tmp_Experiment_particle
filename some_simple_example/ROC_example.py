###Test in linear regression, ROC, AUC 01/21/2019
print(__doc__)

import numpy as np 
import matplotlib.pyplot as plt 
from itertools import cycle

from sklearn import svm,datasets
from sklearn.metrics import roc_curve, auc
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import label_binarize
from sklearn.multiclass import OneVsRestClassifier
from scipy import interp

iris = datasets.load_iris()
X = iris.data
y = iris.target
#label_binarize(y,classes) the for each "y" is [class of 1 , class of 2, class of 3])
#ex: ([1,6],[1,2,4,6]) => [1,0,0,0][0,0,0,1]
y = label_binarize(y,classes = [0,1,2])
#y.shape(1) = 3
n_classes = y.shape[1]
#np.random.RandomState(seed)
random_state = np.random.RandomState(0)
n_samples, n_features = X.shape
#np.c_[np.array[a1,a2,a3...],np.array[b1,b2,b3...]) =>
#[[a1,b1],[a2,b2],[a3,b3]....]
X = np.c_[X, random_state.randn(n_samples, 200 * n_features)]
## shuffle and split training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=.5,
                                                    random_state=0)

## Learn to predict each class against the other
classifier = OneVsRestClassifier(svm.SVC(kernel='linear', probability=True,
                                 random_state=random_state))
y_score = classifier.fit(X_train, y_train).decision_function(X_test)
####Above is for Machine Learning 

####Below is to get ROC and AUC, if you have already used keras, you can ignore above### 

## Compute ROC curve and ROC area for each class
#In 'tmp_keras_for_HGCAL_MLP_number.py', we have 
#index0_testing and prediction in line 137, 
#index0_testing = fpr[i], prediction = tpr[i]
fpr = dict()
tpr = dict()
roc_auc = dict()
for i in range(n_classes):
    fpr[i], tpr[i], _ = roc_curve(y_test[:, i], y_score[:, i])
    roc_auc[i] = auc(fpr[i], tpr[i])

# Compute micro-average ROC curve and ROC area
fpr["micro"], tpr["micro"], _ = roc_curve(y_test.ravel(), y_score.ravel())
roc_auc["micro"] = auc(fpr["micro"], tpr["micro"])

plt.figure()
lw = 2
plt.plot(fpr[2], tpr[2], color='darkorange',
         lw=lw, label='ROC curve (area = %0.2f)' % roc_auc[2])
#####Background(1-eff.) like in TMVA###
##plt.plot(fpr[2], 1-tpr[2], color='darkorange',
##         lw=lw, label='ROC curve (area = %0.2f)' % roc_auc[2])

###x-axis(0 to 1) y_axis(0 to 1)###
plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('Receiver operating characteristic example')
plt.legend(loc="lower right")
plt.show()
