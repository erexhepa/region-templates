/*
 * This file was created automatically from SUIF
 *   on Wed Oct 27 11:11:40 2010.
 *
 * Created by:
 * s2c 1.3.0.1 (plus local changes) compiled Tue Oct 12 14:23:42 EDT 2010 by tiwari on spoon
 *     Based on SUIF distribution 1.3.0.1
 *     Linked with:
 *   libsuif1 1.3.0.1 (plus local changes) compiled Tue Oct 12 14:23:10 EDT 2010 by tiwari on spoon
 *   libuseful 1.3.0.1 (plus local changes) compiled Tue Oct 12 14:23:17 EDT 2010 by tiwari on spoon
 */


#define __suif_min(x,y) ((x)<(y)?(x):(y))

struct hypre_Box_struct { int imin[3];
                          int imax[3]; };
struct hypre_BoxArray_struct { struct hypre_Box_struct *boxes;
                               int size;
                               int alloc_size; };
struct hypre_RankLink_struct { int rank;
                               struct hypre_RankLink_struct *next; };
struct hypre_BoxNeighbors_struct { struct hypre_BoxArray_struct *boxes;
                                   int *procs;
                                   int *ids;
                                   int first_local;
                                   int num_local;
                                   int num_periodic;
                                   struct hypre_RankLink_struct *(((*rank_links)[3])[3])[3]; };
struct hypre_StructGrid_struct { int comm;
                                 int dim;
                                 struct hypre_BoxArray_struct *boxes;
                                 int *ids;
                                 struct hypre_BoxNeighbors_struct *neighbors;
                                 int max_distance;
                                 struct hypre_Box_struct *bounding_box;
                                 int local_size;
                                 int global_size;
                                 int periodic[3];
                                 int ref_count; };
struct hypre_StructStencil_struct { int (*shape)[3];
                                    int size;
                                    int max_offset;
                                    int dim;
                                    int ref_count; };
struct hypre_CommTypeEntry_struct { int imin[3];
                                    int imax[3];
                                    int offset;
                                    int dim;
                                    int length_array[4];
                                    int stride_array[4]; };
struct hypre_CommType_struct { struct hypre_CommTypeEntry_struct **comm_entries;
                               int num_entries; };
struct hypre_CommPkg_struct { int num_values;
                              int comm;
                              int num_sends;
                              int num_recvs;
                              int *send_procs;
                              int *recv_procs;
                              struct hypre_CommType_struct **send_types;
                              struct hypre_CommType_struct **recv_types;
                              int *send_mpi_types;
                              int *recv_mpi_types;
                              struct hypre_CommType_struct *copy_from_type;
                              struct hypre_CommType_struct *copy_to_type; };
struct hypre_StructMatrix_struct { int comm;
                                   struct hypre_StructGrid_struct *grid;
                                   struct hypre_StructStencil_struct *user_stencil;
                                   struct hypre_StructStencil_struct *stencil;
                                   int num_values;
                                   struct hypre_BoxArray_struct *data_space;
                                   double *data;
                                   int data_alloced;
                                   int data_size;
                                   int **data_indices;
                                   int symmetric;
                                   int *symm_elements;
                                   int num_ghost[6];
                                   int global_size;
                                   struct hypre_CommPkg_struct *comm_pkg;
                                   int ref_count; };

extern void OUT__1__6119__(void **);

extern void OUT__1__6119__(void **__out_argv)
  {
    struct hypre_StructMatrix_struct *A;
    int ri;
    double *rp;
    int stencil_size;
    int i;
    int (*dxp_s)[15];
    int hypre__sy1;
    int hypre__sz1;
    int hypre__sy2;
    int hypre__sz2;
    int hypre__sy3;
    int hypre__sz3;
    int hypre__mx;
    int hypre__my;
    int hypre__mz;
    int si;
    int ii;
    int jj;
    int kk;
    const double *Ap_0;
    const double *xp_0;
    double *suif_tmp;
    int over1;
    int _t12;
    int _t10;
    int _t11;
    int _t13;
    int _t14;
    int _t15;
    int _t16;
    int _t17;
    int _t18;
    int _t19;
    int _t20;
    int _t21;
    int _t22;
    int _t23;
    int _t24;
    int _t25;
    int _t26;
    int _t27;
    int t2;
    int t4;
    int t6;
    int t8;
    int t10;
    int t14;
    int t12;

    A = *(struct hypre_StructMatrix_struct **)__out_argv[20];
    ri = *(int *)__out_argv[19];
    rp = *(double **)__out_argv[18];
    stencil_size = *(int *)__out_argv[17];
    i = *(int *)__out_argv[16];
    dxp_s = __out_argv[15];
    hypre__sy1 = *(int *)__out_argv[14];
    hypre__sz1 = *(int *)__out_argv[13];
    hypre__sy2 = *(int *)__out_argv[12];
    hypre__sz2 = *(int *)__out_argv[11];
    hypre__sy3 = *(int *)__out_argv[10];
    hypre__sz3 = *(int *)__out_argv[9];
    hypre__mx = *(int *)__out_argv[8];
    hypre__my = *(int *)__out_argv[7];
    hypre__mz = *(int *)__out_argv[6];
    si = *(int *)__out_argv[5];
    ii = *(int *)__out_argv[4];
    jj = *(int *)__out_argv[3];
    kk = *(int *)__out_argv[2];
    Ap_0 = *(const double **)__out_argv[1];
    xp_0 = *(const double **)*__out_argv;
    over1 = 0;
    for (t2 = 0; t2 <= hypre__mz - 1; t2 += 12)
      {
        for (t4 = 0; t4 <= hypre__my - 1; t4 += 12)
          {
            for (t6 = 0; t6 <= hypre__mx - 1; t6 += 12)
              {
                for (t8 = t2; t8 <= __suif_min(t2 + 11, hypre__mz - 1); t8++)
                  {
                    for (t10 = t4; t10 <= __suif_min(t4 + 11, hypre__my - 1); t10++)
                      {
                        over1 = stencil_size % 2;
                        for (t12 = 0; t12 <= stencil_size - over1 - 1; t12 += 2)
                          {
                            for (t14 = t6; t14 <= __suif_min(hypre__mx - 1, t6 + 11); t14++)
                              {
                                suif_tmp = &rp[ri + t14 + t10 * hypre__sy3 + t8 * hypre__sz3];
                                *suif_tmp = *suif_tmp - Ap_0[t14 + t10 * hypre__sy1 + t8 * hypre__sz1 + A->data_indices[i][t12]] * xp_0[t14 + t10 * hypre__sy2 + t8 * hypre__sz2 + ((int *)dxp_s)[t12]];
                                suif_tmp = &rp[ri + t14 + t10 * hypre__sy3 + t8 * hypre__sz3];
                                *suif_tmp = *suif_tmp - Ap_0[t14 + t10 * hypre__sy1 + t8 * hypre__sz1 + A->data_indices[i][t12 + 1]] * xp_0[t14 + t10 * hypre__sy2 + t8 * hypre__sz2 + ((int *)dxp_s)[t12 + 1]];
                              }
                          }
                        if (1 <= over1)
                          {
                            for (t14 = t6; t14 <= __suif_min(hypre__mx - 1, t6 + 11); t14++)
                              {
                                suif_tmp = &rp[ri + t14 + t10 * hypre__sy3 + t8 * hypre__sz3];
                                *suif_tmp = *suif_tmp - Ap_0[t14 + t10 * hypre__sy1 + t8 * hypre__sz1 + A->data_indices[i][stencil_size - 1]] * xp_0[t14 + t10 * hypre__sy2 + t8 * hypre__sz2 + ((int *)dxp_s)[stencil_size - 1]];
                              }
                          }
                      }
                  }
              }
          }
      }
    *(int *)__out_argv[2] = kk;
    *(int *)__out_argv[3] = jj;
    *(int *)__out_argv[4] = ii;
    *(int *)__out_argv[5] = si;
    *(double **)__out_argv[18] = rp;
    *(struct hypre_StructMatrix_struct **)__out_argv[20] = A;
    return;
  }
