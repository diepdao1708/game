#include "CollisionManager.h"

CollisionDir CollisionManager::Check(sf::CircleShape ball, sf::RectangleShape shape)
{
	Vector2f vtShape = shape.getPosition();
	Vector2f vtBall = ball.getPosition();
	Vector2f sizeShape = shape.getSize();
	sizeShape *= 0.5f;

	float Ax = vtBall.x;
	float Ay = vtBall.y;
	if (vtBall.x < vtShape.x - sizeShape.x) Ax = vtShape.x - sizeShape.x;
	else
	{
		if (vtBall.x > vtShape.x + sizeShape.x) Ax = vtShape.x + sizeShape.x;
	}
	if (vtBall.y < vtShape.y - sizeShape.y) Ay = vtShape.y - sizeShape.y;
	else
	{
		if (vtBall.y > vtShape.y + sizeShape.y) Ay = vtShape.y + sizeShape.y;
	}
	float dx = vtBall.x - Ax;
	float dy = vtBall.y - Ay;
	if ((dx * dx + dy * dy) <= (ball.getRadius() * ball.getRadius()))
	{
		if (vtBall.y < vtShape.y - sizeShape.y)
		{
			if (vtBall.x < vtShape.x - sizeShape.x) return top_left;
			else
			{
				if (vtBall.x > vtShape.x + sizeShape.x) return top_right;
				else return top;
			}
		}
		else
		{
			if (vtBall.y > vtShape.y + sizeShape.y)
			{
				if (vtBall.x < vtShape.x - sizeShape.x) return bottom_left;
				else
				{
					if (vtBall.x > vtShape.x + sizeShape.x) return bottom_right;
					else return bottom;
				}
			}
			else if (vtBall.y >= vtShape.y - sizeShape.y && vtBall.y <= vtShape.y + sizeShape.y)
			{
				if (vtBall.x < vtShape.x - sizeShape.x) return Left;
				if (vtBall.x > vtShape.x + sizeShape.x) return Right;
			}

		}
	}
	if (vtBall.x < 20) return left_wall;
	if (vtBall.x > 680) return right_wall;
	if (vtBall.y < 20) return top_wall;
	if (vtBall.y > 880) return bottom_wall;
	return NO;
}

CollisionDir CollisionManager::Check(Ball &ball, PointBlock &shape)
{
	if (ball.isActive() == false) return NO;


	Vector2f vtShape = shape.getPosition();
	Vector2f vtBall = ball.getPosition();
	Vector2f sizeShape = shape.getSize();
	sizeShape *= 0.5f;

	float Ax = vtBall.x;
	float Ay = vtBall.y;

	if (vtBall.x < 20) return left_wall;
	if (vtBall.x > 680) return right_wall;
	if (vtBall.y < 20) return top_wall;
	if (vtBall.y > 880) return bottom_wall;
	if (shape.isActive() == false) return NO;
	if (vtBall.x < vtShape.x - sizeShape.x) Ax = vtShape.x - sizeShape.x;
	else
	{
		if (vtBall.x > vtShape.x + sizeShape.x) Ax = vtShape.x + sizeShape.x;
	}
	if (vtBall.y < vtShape.y - sizeShape.y) Ay = vtShape.y - sizeShape.y;
	else
	{
		if (vtBall.y > vtShape.y + sizeShape.y) Ay = vtShape.y + sizeShape.y;
	}
	float dx = vtBall.x - Ax;
	float dy = vtBall.y - Ay;
	if ((dx * dx + dy * dy) <= (ball.getRadius() * ball.getRadius()))
	{
		if (vtBall.y < vtShape.y - sizeShape.y)
		{
			if (vtBall.x < vtShape.x - sizeShape.x) return top_left;
			else
			{
				if (vtBall.x > vtShape.x + sizeShape.x) return top_right;
				else return top;
			}

		}
		else
		{
			if (vtBall.y > vtShape.y + sizeShape.y)
			{
				if (vtBall.x < vtShape.x - sizeShape.x) return bottom_left;
				else
				{
					if (vtBall.x > vtShape.x + sizeShape.x) return bottom_right;
					else return bottom;
				}
			}
			else if (vtBall.y >= vtShape.y - sizeShape.y && vtBall.y <= vtShape.y + sizeShape.y)
			{
				if (vtBall.x < vtShape.x - sizeShape.x) return Left;
				if (vtBall.x > vtShape.x + sizeShape.x) return Right;
			}

		}
	}
	return NO;
}

Vector2f CollisionManager::getVelocity(sf::CircleShape ball, sf::RectangleShape shape, Vector2f velocity)
{
	int n = CollisionManager::Check(ball, shape);
	if (n == 9) // top_wall
	{
		velocity.y = abs(velocity.y);
	}
	if (n == 10) // bottom_wall
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	if (n == 11) // left_wall
	{
		velocity.x = abs(velocity.x);
	}
	if (n == 12) // right_wall
	{
		velocity.x = -abs(velocity.x);
	}
	if (n == 1) // top
	{
		velocity.y = -abs(velocity.y);
	}
	if (n == 2) // bottom
	{
		velocity.y = abs(velocity.y);
	}
	if (n == 3) // left
	{
		velocity.x = -abs(velocity.x);
	}
	if (n == 4) // right
	{
		velocity.x = abs(velocity.x);
	}
	if (n == 5) // top_left
	{
		velocity.y = -abs(velocity.y);
		velocity.x = -abs(velocity.x);
	}
	if (n == 6) // top_right
	{
		velocity.y = -abs(velocity.y);
		velocity.x = abs(velocity.x);
	}
	if (n == 7) // bottom_left
	{
		velocity.x = -abs(velocity.x);
		velocity.y = abs(velocity.y);
	}
	if (n == 8) // bottom_right
	{
		velocity.y = abs(velocity.y);
		velocity.x = abs(velocity.x);
	}
	return velocity;
}

Vector2f CollisionManager::getVelocity(Ball &ball, PointBlock &shape, Vector2f velocity)
{
	int n = CollisionManager::Check(ball, shape);

	if (n == 9) // top_wall
	{
		velocity.y = abs(velocity.y);
	}
	if (n == 10) // bottom_wall
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	if (n == 11) // left_wall
	{
		velocity.x = abs(velocity.x);
	}
	if (n == 12) // right_wall
	{
		velocity.x = -abs(velocity.x);
	}
	if (n == 1) // top
	{
		velocity.y = -abs(velocity.y);
	}
	if (n == 2) // bottom
	{
		velocity.y = abs(velocity.y);
	}
	if (n == 3) // left
	{
		velocity.x = -abs(velocity.x);
	}
	if (n == 4) // right
	{
		velocity.x = abs(velocity.x);
	}
	if (n == 5) // top_left
	{
		velocity.y = -abs(velocity.y);
		velocity.x = -abs(velocity.x);
	}
	if (n == 6) // top_right
	{
		velocity.y = -abs(velocity.y);
		velocity.x = abs(velocity.x);
	}
	if (n == 7) // bottom_left
	{
		velocity.x = -abs(velocity.x);
		velocity.y = abs(velocity.y);
	}
	if (n == 8) // bottom_right
	{
		velocity.y = abs(velocity.y);
		velocity.x = abs(velocity.x);
	}
	if (n >= 1 && n <= 8) {
		ball.SetCollider(Tag_PointBlock);
		shape.SetCollider(Tag_Ball);
		shape.setNumCollider(shape.getNumCollider()+1);
	}
	else
	{
		ball.SetCollider(Tag_Null);
		shape.SetCollider(Tag_Null);
	}
	return velocity;
}

void CollisionManager::Push(Entity& entiy)
{
	m_ListObject.push_back(&entiy);
}

void CollisionManager::Update(float deltaTime)
{
	for (auto it : m_ListObject)
	{
		for (auto jt : m_ListObject)
		{
			if (it->getTag() == Tag_Ball && jt->getTag() == Tag_PointBlock)
			{		
				jt->LoseHP(jt->getNumCollider());
				jt->setNumCollider(0);
			}
		}
	}
}
