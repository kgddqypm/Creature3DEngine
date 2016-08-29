/* -*-c++-*- OpenThreads library, Copyright (C) 2002 - 2007  The Open Thread Group
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/


//
// ScopedLock and ReverseScopedLock templates
// ~~~~~~~
//
#ifndef CRCORE_ScopedLock_H
#define CRCORE_ScopedLock_H

namespace CRCore{

template <class M> class ScopedLock
{
    private:
        M& m_lock;
        ScopedLock(const ScopedLock&); // prevent copy
        ScopedLock& operator=(const ScopedLock&); // prevent assign
    public:
        explicit ScopedLock(M& m):m_lock(m) {m_lock.lock();}
        ~ScopedLock(){m_lock.unlock();}
};

template <class M> class ReverseScopedLock
{
    private:
        M& m_lock;
        ReverseScopedLock(const ReverseScopedLock&); // prevent copy
        ReverseScopedLock& operator=(const ReverseScopedLock&); // prevent assign
    public:
        explicit ReverseScopedLock(M& m):m_lock(m) {m_lock.unlock();}
        ~ReverseScopedLock(){m_lock.lock();}
};

}
#endif
