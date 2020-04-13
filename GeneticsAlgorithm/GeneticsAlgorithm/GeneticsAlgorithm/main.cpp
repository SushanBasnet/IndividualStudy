//
//  main.cpp
//  GeneticsAlgorithm
//
//  Created by Sushan Basnet on 4/12/20.
//  Copyright © 2020 Sushan Basnet. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const string GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

const string TARGET = "Hello, my name is Sushan Basnet!";



char mutatedGenes() {
    int index = (rand()% GENES.size());
    return GENES[index];
}

//a gnome is a starting set of random genes (initial chromosome)
string createGnome() {
    int len = (int) TARGET.size();
    string gnome = "";
    for (int i=0; i < len; i++) {
        gnome += mutatedGenes();
    }
    return gnome;
}


class Individual {
public:
    string chromosome; //chromosome is a set of genes
    
    int fitness;
    Individual(string chromosome) {
        
        this->chromosome = chromosome;
        fitness = calculateFitness();
    }
    
    int calculateFitness() {
        int fit=0;
        for(int i=0; i<chromosome.size(); i++) {
            
            if (chromosome[i] != TARGET[i]) {
                fit++;
            }
        }
        return fit;
    }
    
    Individual crossOver(Individual parent2) {
        string childChromosome = "";
        for(int i=0; i < chromosome.size(); i++) {
            float p = (rand()%100)/100.0; // 0 to 0.99
            if (p<0.45) childChromosome += chromosome[i];
            else if (p < 0.9) childChromosome += parent2.chromosome[i];
            else childChromosome += mutatedGenes();
        }
        return Individual(childChromosome);
        
    }
    
    bool operator<(const Individual &ind2) {
        if (fitness < ind2.fitness) return true;
        return false;
    }
    
    
};


bool comparator(Individual ind1, Individual ind2) {
    return (ind1.fitness < ind2.fitness);
}

int main(int argc, const char * argv[]) {
    //set of genes to choose from
    
    int generation = 0;
    vector<Individual> population;
    
    for (int i=0; i<100; i++) {
        string gnome = createGnome();
        population.push_back(Individual(gnome));
    }
    
    while (1) {
        //main loop , loop until target found
        //first sort by fitness (fitness 0 = target )
        sort(population.begin(), population.end(), comparator);
        
        if (population[0].fitness == 0) break;
        vector<Individual> newGeneration;
        //10% of fittest population goes to next generation
        int i;
        for( i=0; i < (population.size()/10); i++) {
            newGeneration.push_back(population[i]);
        }
        
        //randomly pick 2 from top 50% of fittest population && perform crossover
        for (; i<population.size(); i++) {
            int r = rand()%(population.size()/2); //top 50 pool --pick 2 parents
            Individual parent1 = population[r];
            r = rand()%(population.size()/2);
            Individual parent2 = population[r];
            Individual child = parent1.crossOver(parent2);
            
            newGeneration.push_back(child);
            
        }
        
        population = newGeneration;
        cout << "Generation: " << generation++ << endl;
        cout << "Top Fitness: " << population[0].fitness << endl;
        cout << "String Data: " << population[0].chromosome << endl;
    }
    
    cout << "******************** Target Reached ************" << endl;
    cout << "Generation: " << generation++ << endl;
    cout << "Top Fitness: " << population[0].fitness;
    cout << "String Data: " << population[0].chromosome;
    
    
}
