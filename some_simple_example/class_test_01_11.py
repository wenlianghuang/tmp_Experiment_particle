'''
    In this code, they are two classes and class Income input TaxReturn and get self.income.self.sal_wge.
    We can get sub of Object
'''

class Income:
    def __init__(self,sal_wge):
        self.sal_wge = sal_wge

class TaxReturn:
    def __init__(self,income=None):
        self.income = Income(sal_wge=0)

t = TaxReturn()
print(t.income.sal_wge)

