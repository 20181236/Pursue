#pragma once 

#include <math.h>

class Vector2D {
public:
    Vector2D(float x, float y) : m_x(x) , m_y(y) {}
    Vector2D(){};
    float getX() { return m_x; }
    float getY() { return m_y; }
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

    void limit(float max) // 추가: max 값을 넘었다면 길이를 max 값으로 보정
    {
      float l = length();
      if (l > 0)
      {
        if (l > max)
        {
          (*this) *= 1 / l;
          (*this) *= max;
        }
      }
    }
    
    // 내적 연산
    static float dot(const Vector2D& v1, const Vector2D& v2)
    {
      Vector2D vn1 = v1;
      vn1.normalize();
      Vector2D vn2 = v2;
      vn2.normalize();

      float vn = vn1.m_x * vn2.m_x + vn1.m_y + vn2.m_y;
      
      return vn;
    }

    static float cross(const Vector2D& v1, const Vector2D& v2)
    {
      Vector2D vn1 = v1;
      vn1.normalize();
      Vector2D vn2 = v2;
      vn2.normalize();

      float vn = vn1.m_x * vn2.m_y - vn2.m_x * vn1.m_y;

      return vn;
    }

    float length() { return sqrt(m_x * m_x + m_y * m_y); }

// 연산자 오버라이딩 SDL Vector부분에 있음

    Vector2D operator+(const Vector2D& v2) const
    {
        return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
    }

    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        return v1; 
    }

    Vector2D operator-(const Vector2D& v2) const
    {
        return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
    }

    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        return v1; 
    }

    Vector2D operator*(float scalar)
    {
        return Vector2D(m_x * scalar, m_y * scalar);
    }

    Vector2D& operator*=(float scalar)
    {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }
    
    Vector2D operator/(float scalar)
    {
        return Vector2D(m_x / scalar, m_y / scalar);
    }

    Vector2D& operator/=(float scalar)
    {
        m_x /= scalar;
        m_y /= scalar;
        return *this;
    }
    void normalize()
    {
        float l = length();
        if (l > 0)   // /벡터 정규화 벡터크기1 방향변경X
        {
            (*this) *= 1 / l;
        }
    }

    void add(Vector2D* scalar)
    {
      m_x = m_x + scalar->getX();
      m_y = m_y + scalar->getY();
    }
    void sub(Vector2D* scalar)
    {
      m_x = m_x - scalar->getX();
      m_y = m_y - scalar->getY();
    }

    void mult(float scalar)
    {
      m_x = m_x * scalar;
      m_y = m_y * scalar;
    }
    void div(float scalar)
    {
      m_x = m_x / scalar;
      m_y = m_y / scalar;
    }
    void force(float force,float mass)//mass 매게변수 넣어줘야함
    {
    ??? f = div(force, mass);
    return add(f);
    }

private:
    float m_x;
    float m_y;
};