# forel
Implementation of forel (FORmal ELement) clustering algorithm in C (standard C89/C90)  
## About forel  
FOREL is an iterative clustering algorithm developed by the Soviet/Russian mathematician N.G. Zagoruiko from Novosibirsk in the 1960s to solve tasks in paleontology.  
The main idea of the algorithm is to combine objects in the areas of their greatest concentration into one cluster.  
#### Input data:
  +  $X=\mathrm{x}_{i=1,j=1}^{n,m}$ — description of objects, where n — number of objects, m — number of attributes;  
  +  $R > 0$ — concentration radius.  
#### Output data:   
  +  $Y=\left\\{y_i|y_i\in ℕ,i=\overline{\left(1,n\right)}\right\\}$ — cluster labels.  
#### Advantages of forel:
  +  Easy to implement;  
  +  The ability to calculate intermediate estimates of the quality of clustering, for example, the length of the chain of local thickenings;  
  +  The presence of many modifications.  
#### Disadvantages of forel:   
  +  Strong dependence of the solution on the input parameter $R$;  
  +  Instability of the algorithm (dependence on the choice of the object for "concentration");  
  +  Poor partitioning of clusters with a complex structure.  
### Steps of forel algorithm  
Step 0. Data preparing (autoscaling): $x_{i,j}=\frac{x_{i,j}-\mathrm{E_{X^{j}}}}{\sigma_{X^{j}}}$;  
Step 1. Mark all objects as "unselected";  
Step 2. Set a randomly selected object among the unselected ones from the dataset as a local center of condensation;  
Step 3. Mark all objects located at a distance of no more than R from the center of condensation;  
Step 4. Find a new center of condensation for them;   
Step 5. If the old and new centers coincide, then go to step 6, otherwise to step 3, making the new center of condensation the current one;  
Step 6. Repeat steps 2÷5 until the unmarked objects remain.  
## Example of usage
```
git clone https://github.com/KlimentLagrangiewicz/forel
cd forel/  
cmake .  
cmake --build .  
./forel ./examplesDataSets/iris/test150 150 4 2.1 ./examplesDataSets/iris/resultFull ./examplesDataSets/iris/ideal150
 ```

