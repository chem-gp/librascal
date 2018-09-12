/**
 * file   atomic_structure.hh
 *
 * @author  Felix Musil <felix.musil@epfl.ch>
 *
 * @date   08 August 2018
 *
 * @brief Lattice class used to compute face distances within the cell and to scale and unscale positions
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

#ifndef ATOMIC_STRUCTURE_H
#define ATOMIC_STRUCTURE_H

#include <Eigen/Dense>
#include <basic_types.hh>
#include <cmath>
#include "structure_managers/json_io.hh"
#include <stdexcept>

namespace rascal {

  template <int Dim>
  struct AtomicStructure {
    /**
       \param cell is a vector a vector of vectors which holds the cell unit
       vectors.
       \param type a vector of integers which holds the atomic type
       (coordination number).
       \param pbc is a 0/1 vector which says, where periodic boundary
       conditions are applied.
       \param position is a vector of vectors which holds the atomic
       positions.
    */
    using Cell_t = Eigen::Matrix<double, Dim, Dim, Eigen::ColMajor>;
    using AtomTypes_t = Eigen::Matrix<int, 1, Eigen::Dynamic>;
    using PBC_t = Eigen::Map<Eigen::Matrix<int, 1, Dim>>;
    using Positions_t = Eigen::Matrix<double, Dim, Eigen::Dynamic,
                                      Eigen::ColMajor>;

    Positions_t positions; //!
    AtomTypes_t atoms_type;
    Cell_t cell;
    PBC_t pbc;
  };

  inline void set_structure(AtomicStructure<2> & s,
                            const Eigen::Ref<const Eigen::MatrixXd> positions,
                            const Eigen::Ref<
                            const Eigen::Matrix<int, Eigen::Dynamic, 1> >  atoms_type,
                            const Eigen::Ref<const Eigen::MatrixXd> cell,
                            const Eigen::Ref<
                            const Eigen::Matrix<int, Eigen::Dynamic, 1> >& pbc) {

    s.cell = cell;
    s.atoms_type = atoms_type;
    s.pbc = pbc;
    s.positions = positions;

  }

  inline void set_structure(AtomicStructure<3>& s,
                            const Eigen::Ref<const Eigen::MatrixXd> positions,
                            const Eigen::Ref<
                            const Eigen::Matrix<int, Eigen::Dynamic, 1> >
                            atoms_type,
                            const Eigen::Ref<const Eigen::MatrixXd> cell,
                            const Eigen::Ref<
                            const Eigen::Matrix<int, Eigen::Dynamic, 1> >& pbc) {
    s.cell = cell;
    s.atoms_type = atoms_type;
    s.pbc = pbc;
    s.positions = positions;

  }

} // rascal

#endif /* ATOMIC_STRUCTURE_H */
