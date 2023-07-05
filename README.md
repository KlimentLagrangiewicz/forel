# FOREL
Implementation of FOREL (FORmal ELement) clustering algorithm in C (standard C89/C90)  
## About FOREL  
FOREL is iterative clustering algorithm designed by soviet/russian mathematician N.G. Zagoruiko from Novosibirsk in 1960-s for decision tasks in palentology.  
The main idea of the algorithm is to combine objects in the areas of their greatest concentration into one cluster.  
#### Input data:
  +  $X=\mathrm{x}_{i=1,j=1}^{n,m}$ — description of objects, where n — number of object, m — number of attributes;  
  +  *R* ∈ ℝ — concentration radius.  
#### Output data:   
  +  $Y=\left\\{y_i|y_i\in ℕ,i\in\overline{\left(1,n\right)}\right\\}$ — cluster labels.  
#### Advantages of FOREL:
  +  Easy to implement;  
  +  The ability to calculate intermediate estimates of the quality of clustering, for example, the length of the chain of local thickenings;  
  +  The presence of many modifications.  
#### Disadvantages of FOREL:   
  +  Strong dependence of the solution on the input parameter R; 
  +  Instability of the algorithm (dependence on the choice of the object for "concentration");  
  +  Poor partitioning of clusters with a complex structure.  
### Steps of FOREL algorithm  
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

