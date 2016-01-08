#pragma once

#include "types.hpp"
#include "constants.hpp"

using namespace arma;

class Model
{
public:
	typedef arma::vec::fixed<states::state_size> state_type;
	typedef state_type deriv_type;

	typedef arma::vec::fixed<outputs::output_size> observer_type;
	typedef arma::vec::fixed<inputs::input_size> input_type;
	typedef arma::vec::fixed<mids::intermediate_size> intermediate_type;
	typedef arma::mat::fixed<config::buffer_headers,config::buffer_size> buffer_type;

	typedef double value_type;
	typedef double time_type;

public:

	static void rhs(
		const state_type 			&x,
		state_type 					&x_dot,
		const time_type				&t,
		const intermediate_type 	&last_observed_mids,
		const time_type 			&last_observed_t,
		input_type					&u
		);

	static void observer(
		const state_type 			&x ,
		const double 				&t,
		observer_type 				&ymat,
		const intermediate_type 	&last_observed_mids,
		const time_type 			&last_observed_t,
		input_type					&u
		);

	static void intermediates(
		const input_type			&u,
		const state_type			&x,
		intermediate_type			&mid,
		const time_type				&t,
		const intermediate_type		&last_observed_mids,
		const time_type				&last_observed_t
		);

	static double input(const time_type t,input_type &u)
	{
		u(inputs::v_in)=(t>1.0?1.0:0.0);

		double next_sudden_change_time=-1;
		return next_sudden_change_time;
	}

protected:

	const static std::size_t N=physics::N;

	static arma::mat::fixed<2*N,2*N> get_A()
	{
		const double L=physics::L;
		const double C=physics::C;
		const double R=physics::R;
		const double G=physics::G;
		const int first_0=0;
		const int N_0=N-1;

		arma::mat::fixed<2*N,2*N> A;
		A.zeros();
		long n_0;
		long n_1;

		for(n_1=1;n_1<=long(N-1);n_1++)
		{
			n_0=n_1-1;
			A(n_0,n_0)=-G/C;
			A(n_0,N+n_0)=1.0/L;
			A(n_0,N+n_0+1)=-1.0/L;
		}

		A(N_0,N_0)=-G/C;
		A(N_0,N+N_0)=1.0/L;

		A(N_0+1,first_0)=-1.0/C;
		A(N_0+1,N+first_0)=-R/L;

		for(n_1=2;n_1<=long(N);n_1++)
		{
			n_0=n_1-1;
			A(n_0+N,n_0-1)=1.0/C;
			A(n_0+N,n_0)=-1.0/C;
			A(n_0+N,N+n_0)=-R/L;
		}

		return A;
	}

};

#include "autogenerated/model_observer.hpp"
#include "model_mids.hpp"
#include "model_rhs.hpp"
