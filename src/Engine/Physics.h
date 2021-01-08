#pragma once
#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <cmath>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

namespace myengine
{
	/**
	*Contains mathematics to use in physics. Un-used since using bullet
	*/
	class Physics
	{
	public:
		const static double G;
		const static double g;
		static float deltaT;
		
		//Vector Maths
		/**
		*Calculates the differnce between two vectors.
		*/
		glm::vec3 static Calculate3DVector(const glm::vec3& i_point1,
			const glm::vec3& i_point2);
		/**
		*Calculates the distance between two 3D points.
		*/
		float static ComputeDistanceBetween3DPoints(const glm::vec3& i_Point1,
			const glm::vec3& i_Point2);
		/**
		*Calculates a normal direction of a triangle defined by three 3D vectors.
		*/
		glm::vec3 static ComputeNormalToTriangleDefinedBy3DPoints(glm::vec3 const&
			i_Point1, glm::vec3 const& i_Point2, glm::vec3 const& i_Point3);
		/**
		*Calculates a normal from two 3D vectors.
		*/
		glm::vec3 static ComputeNormalTo3DVectors(glm::vec3 const& i_Vector1,
			glm::vec3 const& i_Vector2);
		/**
		*Calculates the volume of a parellelepiped.
		*/
		float static ComputeVolumeOfParallelepiped(glm::vec3 const& i_VectorA,
			glm::vec3 const& i_VectorB, glm::vec3 const& i_VectorC);




		//Velocity and Acceleration Maths
		/**
		*Calculates velocity of an object going between two points in a given time.
		*/
		double static Velocity(const double& i_PointOne, const double& i_PointZero,
			const double& i_Time);
		/**
		*Calculates the change acceleration of an object using two velocities and a time.
		*/
		double static Acceleration(const double& i_VelocityOne, const double&
			i_VelocityZero, const double& i_Time);




		//Kinematic Equations
		/**
		*Computes displacement using the current velocity, the acceleration and the time.
		*/
		double static ComputeDisplacmentUsingAcceleration(const double&
			i_InitialVelocity, const double& i_Acceleration, const double i_Time);
		/**
		*Computes the final velocty of an object using initial velocity, acceleration and the time.
		*/
		double static ComputeFinalVelocity(const double& i_InitialVelocity, const
			double& i_Acceleration, const double& i_Time);
		/**
		*Computes the final velocity squared.
		*/
		double static ComputeFinalVelocitySquared(const double&
			i_InitialVelocitySquared, const double& i_Acceleration, const double&
			i_Displacement);
		/**
		*Computes the displacement using initial velocity, final velocity and the time.
		*/
		double static ComputeDisplacementUsingVelocities(const double&
			i_InitialVelocity, const double& i_FinalVelocity, const double&
			i_Timedouble);



		//Geometry Functions
		/**
		*Smoothly lerps the float value between one value to another.
		*/
		float static Lerp(const float& i_PointA, const float& i_PointB,
			const float& i_DeltaT);
		/**
		*Smoothly lerps the vector 3 value between one value to another.
		*/
		glm::vec3 static Lerp(const glm::vec3& i_PointA, const glm::vec3& i_PointB,
			const float& i_DeltaT);



		//Basic Newtonian Physics
		/**
		*Computes the force due to gravity.
		*/
		double static ComputeForceDueToGravity(const double& i_MassOne,
			const double& i_MassTwo, const double i_RadiusOne,
			const double& i_RadiusTwo);
		/**
		*Computes centripetal acceleration.
		*/
		double static ComputeCentripetalAcceleration(const double& i_Velocity,
			const double& i_Radius);
		/**
		*Computes the gravitational potential energy.
		*/
		double static ComputeGravitationalPE(const double& i_H0, const double& i_Mass);
		/**
		*Computes the kinetic energy.
		*/
		double static ComputeKineticEnergy(const double& i_Velocity, const double& i_Mass);
		/**
		*Computes the force of an object.
		*/
		double static ComputeForce(const double& i_Mass, const double& i_Aceleration);
		/**
		*Computes the freefall velocity due to gravity without drag.
		*/
		double static FreeFallVelocityDueToGravity();
		/**
		*Computes the freefall velocity due to gravity with drag.
		*/
		double static FreeFallVelocityWithDrag(const double& i_mass,
			const double& i_AirDensity, const double& i_DragCoefficient, const double& i_Area);
		/**
		*Computes the terminal velocity of an object.
		*/
		double static ComputeTerminalVelocity(const double& i_mass,
			const double& i_AirDensity, const double& i_DragCoefficient,
			const double& i_Area);
	};
}

#endif