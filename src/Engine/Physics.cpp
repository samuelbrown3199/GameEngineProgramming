#include "Physics.h"

namespace myengine
{

	const double Physics::G = 0.0000000000667;
	const double Physics::g = 9.80;

	//Vector Maths
	glm::vec3 Physics::Calculate3DVector(const glm::vec3& i_point1,
		const glm::vec3& i_point2)
	{
		glm::vec3 output = glm::operator-(i_point1, i_point2);
		return output;
	}
	float Physics::ComputeDistanceBetween3DPoints(const glm::vec3& i_Point1,
		const glm::vec3& i_Point2)
	{
		float distance = static_cast<float> (glm::distance(i_Point1, i_Point2));
		return distance;
	}
	glm::vec3 Physics::ComputeNormalToTriangleDefinedBy3DPoints(glm::vec3 const&
		i_Point1, glm::vec3 const& i_Point2, glm::vec3 const& i_Point3)
	{
		glm::vec3 normal = glm::normalize(glm::cross(i_Point1 - i_Point2, i_Point2 - i_Point3));
		return normal;
	}
	glm::vec3 Physics::ComputeNormalTo3DVectors(glm::vec3 const& i_Vector1,
		glm::vec3 const& i_Vector2)
	{
		glm::vec3 normal = glm::normalize(glm::cross(i_Vector1, i_Vector2));
		return normal;
	}
	float Physics::ComputeVolumeOfParallelepiped(glm::vec3 const& i_VectorA,
		glm::vec3 const& i_VectorB, glm::vec3 const& i_VectorC)
	{
		float volume = glm::dot(i_VectorA, glm::cross(i_VectorB, i_VectorC));
		return volume;
	}


	
	//Velocity and Acceleration Maths
	double Physics::Velocity(const double& i_PointOne, const double&
		i_PointZero, const double& i_Time)
	{
		double velocity = 0;
		if (i_Time > 0)
			velocity = (i_PointOne - i_PointZero) / i_Time;

		return velocity;
	}
	double Physics::Acceleration(const double& i_VelocityOne, const double&
		i_VelocityZero, const double& i_Time)
	{
		double acceleration = 0;
		if (i_Time > 0)
			acceleration = (i_VelocityOne - i_VelocityZero) / i_Time;

		return acceleration;
	}


	//Kinematic Equations
	double Physics::ComputeDisplacmentUsingAcceleration(const double&
		i_InitialVelocity, const double& i_Acceleation, const double i_Time)
	{
		double displacement = (i_InitialVelocity * i_Time) + (0.5 * i_Acceleation * i_Time * i_Time);
		return displacement;
	}
	double Physics::ComputeFinalVelocity(const double& i_InitialVelocity,
		const double& i_Acceleration, const double& i_Time)
	{
		double finalVelocity = i_InitialVelocity + (i_Acceleration * i_Time);
		return finalVelocity;
	}
	double Physics::ComputeFinalVelocitySquared(const double&
		i_InitialVelocitySquared, const double& i_Acceleration, const double&
		i_Displacement)
	{
		double finalVelocity = i_InitialVelocitySquared + (2 * i_Acceleration * i_Displacement);
		return finalVelocity;
	}
	double Physics::ComputeDisplacementUsingVelocities(const double&
		i_InitialVelocity, const double& i_FinalVelocity, const double& i_Time)
	{
		double displacement = ((i_InitialVelocity + i_FinalVelocity) / 2) * i_Time;
		return displacement;
	}




	//Geometry Functions
	float Physics::Lerp(const float& i_PointA, const float& i_PointB,
		const float& i_DeltaT)
	{
		float lerpPoint = (((1.0f - i_DeltaT) * i_PointA) + (i_DeltaT * i_PointB));
		return lerpPoint;
	}
	glm::vec3 Physics::Lerp(const glm::vec3& i_PointA, const glm::vec3& i_PointB,
		const float& i_DeltaT)
	{
		glm::vec3 lerpPoint;
		lerpPoint.x = (((1.0f - i_DeltaT) * i_PointA.x) + (i_DeltaT * i_PointB.x));
		lerpPoint.y = (((1.0f - i_DeltaT) * i_PointA.y) + (i_DeltaT * i_PointB.y));
		lerpPoint.z = (((1.0f - i_DeltaT) * i_PointA.z) + (i_DeltaT * i_PointB.z));
		return lerpPoint;
	}


	//Basic Newtonian Physics
	double Physics::ComputeForceDueToGravity(const double& i_MassOne,
		const double& i_MassTwo, const double i_RadiusOne, const double& i_RadiusTwo)
	{
		double radius = i_RadiusOne + i_RadiusTwo;
		double acceleration = ((G * i_MassOne * i_MassTwo) / (radius * radius));
		acceleration /= i_MassTwo;

		return acceleration;
	}
	double Physics::ComputeCentripetalAcceleration(const double&
		i_Velocity, const double& i_Radius)
	{
		double acceleration = (i_Velocity * i_Velocity) / i_Radius;
		return acceleration;
	}
	double Physics::ComputeGravitationalPE(const double& i_H0,
		const double& i_Mass)
	{
		double pe = i_H0 * i_Mass * g;
		return pe;
	}
	double Physics::ComputeKineticEnergy(const double& i_Velocity, const double&
		i_Mass)
	{
		double ke = (i_Mass / 2) * (i_Velocity * i_Velocity);
		return ke;
	}
	double Physics::ComputeForce(const double& i_Mass,
		const double& i_Acceleration)
	{
		double force = i_Mass * i_Acceleration;
		return force;
	}
	double Physics::FreeFallVelocityDueToGravity(const double& i_time)
	{
		double velocity = g * i_time;
		return velocity;
	}
	double Physics::FreeFallVelocityWithDrag(const double& i_time,
		const double& i_mass, const double& i_AirDensity, const double& i_DragCoefficient,
		const double& i_Area)
	{
		double tempVelocity = ComputeTerminalVelocity(i_mass, i_AirDensity, i_DragCoefficient, i_Area);
		double outputVelocity = tanh((g * i_time) / tempVelocity);
		outputVelocity = -tempVelocity * outputVelocity;

		return outputVelocity;
	}
	double Physics::ComputeTerminalVelocity(const double& i_mass, const double& i_AirDensity, const double& i_DragCoefficient, const double& i_Area)
	{
		double terminalVelocity = sqrt((2 * g * i_mass) / (i_AirDensity * i_DragCoefficient * i_Area));
		return terminalVelocity;
	}
}