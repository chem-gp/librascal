/**
 * file   lattice.cc
 *
 * @author  Felix Musil <felix.musil@epfl.ch>
 *
 * @date   05 Apr 2018
 *
 * @brief Implementation of the neighbourhood manager for lammps
 *        neighbourhood lists
 *
 * Copyright © 2018  Felix Musil, COSMO (EPFL), LAMMM (EPFL)
 *
 * rascal is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3, or (at
 * your option) any later version.
 *
 * rascal is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef TEST_NEIGHBOURHOOD_MANAGER_CELL_H
#define TEST_NEIGHBOURHOOD_MANAGER_CELL_H

#include "neighbourhood_managers/neighbourhood_manager_cell.hh"
#include "basic_types.h"


namespace rascal {

  struct ManagerFixture_cell
  {
    ManagerFixture_cell(){
      Eigen::MatrixXd cell(3,3);
      cell << 6.19,2.41,0.21,
              0.00,6.15,1.02,
              0.00,0.00,7.31;
      Eigen::MatrixXd positions(3,22); // 3,22
      positions << 3.689540159937393,5.123016813620886,1.994119731169116,6.818437242389163,2.630056617829216,6.182500355729062,2.114977334498767,6.697579639059512,1.392155450018263,7.420401523540017,2.432242071439904,6.380314902118375,1.112656394115962,7.699900579442317,3.569715877854675,5.242841095703604,3.122826344932127,5.689730628626151,3.248684682453303,5.563872291104976,2.608353462112637,6.204203511445642,
                    5.035681855581504,2.134827911489532,0.946910011088814,6.223599755982222,4.168634519120968,3.001875247950068,1.980327734683430,5.190182032387606,2.943861424421339,4.226648342649697,5.457161501166098,1.713348265904937,1.501663178733906,5.668846588337130,5.208365510425203,1.962144256645833,2.728127406527150,4.442382360543885,2.839975217222644,4.330534549848392,0.744216089807768,6.426293677263268,
                    4.643695520786083,2.662204050783991,1.250682335857938,6.055217235712136,0.860905287815103,6.444994283754972,4.536108843695142,2.769790727874932,5.609177455068640,1.696722116501434,6.703053268421970,0.602846303148105,3.487609972580834,3.818289598989240,1.436734374347541,5.869165197222533,1.054504320562138,6.251395251007936,3.998423858825871,3.307475712744203,5.323662899811682,1.982236671758393;
      std::array<bool,3> pbc{{true,true,true}};
      double cutoff_max{3};  
      std::vector<int> center_ids;
      for (int ii{0}; ii < 22; ++ii) center_ids.push_back(ii);
      manager.build(positions,center_ids,cell,pbc,cutoff_max);
      
    }
        
    ~ManagerFixture_cell() {
      
    }
    
  NeighbourhoodManagerCell manager;
  
  };
}  // rascal

#endif /* TEST__H */